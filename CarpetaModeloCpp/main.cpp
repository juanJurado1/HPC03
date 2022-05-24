#include "EXTRACCION/extraccion.h"
#include "regresionlineal.h"
#include <iostream>
#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[])
{
    /* Se crea el objeto del tipo extracciondata
     * y se incluyen los tres argumentos que hemos de
     * pasar al objeto (dado por el constructor de la clase)*/
    ExtraccionData extraer(argv[1],argv[2],argv[3]);

    RegresionLineal RL;

    /* Se leen los datos del fichero, a traves de la funcion ReadCSV() */
    std::vector<std::vector<std::string>> dataSET= extraer.ReadCSV();

    int filas= dataSET.size()+1;
    int columnas= dataSET[0].size();

    /* Se crea una matrix dinamica double de dimension filasXcolumnas */

    Eigen::MatrixXd DataFrame= extraer.CSVtoEigen(dataSET, filas, columnas);

    /*El objeto CSVtoEigen (similar a un objeto DATAFRAME)
     * se obtiene una matriz matNormal*/
    Eigen::MatrixXd mean= extraer.Promedio(DataFrame);

    Eigen::MatrixXd matNormal= extraer.Normalizador(DataFrame);
    //std::cout<<matNormal<<std::endl<<std::endl;

    /* A continuacion se hara el primer modulo de Machine Learning;
     * Se requiere una clase de Regresion Lineal (Implementacion e Interfaz)
     * Se debe definir un constructor, importar las bibliotecas necesarias, se debe
     * tener en cuenta que el metodo de regresion lineal es un metodo estadistico
     * que define la relacion entre las variables independiente con la variable dependiente.
     * La idea principal es definir una LINEA RECTA (Hiperplano), con sus correspondientes
     * coeficientes (pendientes) y los puntos de corte (y=0).
     * Se tiene diferentes metodos para resolver RL se implementara
     * el metodo de los minimos cuadrados ordinarios (OLS), el OLS es un metodo
     * sencillo y computacionalmente economico. OLS presenta una solucion
     * optima para conjuto de datos complejo. Para el presente caso se tiene un conjunto de datos
     * con multiples variables independientes. Se necesita el algoritmo llamado gradiente descendiente,
     * el objetivo de este es minimizar la FUNCION de COSTO */


    std::cout<<"-------------PROMEDIO-----------------"<<std::endl;
    std::cout<< extraer.Promedio(DataFrame) << std::endl;
    //std::cout<< extraer.DesvStandard(DataFrame) << std::endl;
    std::cout<<"-------------NORMALIZADOR-----------------"<<std::endl;
    std::cout<< extraer.Normalizador(DataFrame) << std::endl;

    Eigen::MatrixXd X_train, y_train, X_test, y_test;
    /* declaramos un objeto para recibir la tupla empaquetada*/
    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> empaquetado= extraer.TrainTestDiv(matNormal, 0.8);

    /*Se necesita desempaquetar la tupla en 4 grupos de datos (Matrices dinamicas duble)*/
    std::tie(X_train, y_train, X_test, y_test)=empaquetado;

    /*Se imprime el total de filas, las filas para entrenamiento, las filas para pruebas en sus dos sabores*/

    /*----------------FILAS----------------*/
    std::cout<<matNormal.rows()<<std::endl;
    std::cout<<X_train.rows()<<std::endl;
    std::cout<<y_train.rows()<<std::endl;
    std::cout<<X_test.rows()<<std::endl;
    std::cout<<y_test.rows()<<std::endl;

    /*----------------COLUMNAS----------------*/

    /*Se necesita imprimir la cantidad de columnas por sabor */
    std::cout<<matNormal.cols()<<std::endl;
    std::cout<<X_train.cols()<<std::endl;
    std::cout<<y_train.cols()<<std::endl;
    std::cout<<X_test.cols()<<std::endl;
    std::cout<<y_test.cols()<<std::endl;

    /*Se tiene en cuenta que la regresion lineal es un metodo estadistico
     * la idea principal es crear un hiperplano con tantas dimensiones como
     * variables indeendientes tenga el conjunto de datos de entrada
     * (pendientes/pesos y ountos de corte).
     * Se hace la prueba del modelo: se crea un vector para prueba y para entrenamiento
     * inicializado en "unos", que corresponde a nuestros features/variables independientes */
    Eigen::VectorXd vectorTrain = Eigen::VectorXd::Ones(X_train.rows());
    Eigen::VectorXd vectorTest = Eigen::VectorXd::Ones(X_test.rows());

    /*Se redimensionan las matrices para ser ubicadas en los vectores anteriores. Similar
     * a reshape de numpy */
    X_train.conservativeResize(X_train.rows(), X_train.cols()+1);
    X_train.col(X_train.cols()-1)=vectorTrain;

    X_test.conservativeResize(X_test.rows(), X_test.cols()+1);
    X_test.col(X_test.cols()-1)=vectorTest;

    /*--------TEST--------*/


    /*Se define el vector Theta, para pasar al algoritmo del GD,
     * basicamente es un vector de ceros del mismo tamaño de entrenamiento
     * adicionalmente se declara el alfa y el numero de iteraciones */
    Eigen::VectorXd vectorTheta= Eigen::VectorXd::Zero(X_train.cols());
    float alfa= 0.01;
    int iterator= 1000;

    Eigen::VectorXd thetaOut;
    std::vector<float> costo;

    std::tuple<Eigen::VectorXd, std::vector<float>> salidaGD= RL.Gradiente(X_train,y_train, vectorTheta,alfa,iterator);
    std::tie(thetaOut, costo)= salidaGD;
    //std::cout<<thetaOut<<std::endl;

    /*Se quiere observar como decrece la funcion de costo*/
    /*for(auto v: costo){
        std::cout<<v<<std::endl;
    }*/

    /*A continuacion con propositos de seguridad y trazabilidad se exporta
     * el vector de costos y el vector Theta a ficheros */
    /*extraer.vectorToFile(costo, "vectorCosto.txt");
    extraer.matrixToFile(thetaOut, "vectorTheta.txt");*/

    /*Con el proposito de ajustar el modelo y hacer las predicciones
     * necesarias, calculamos de nuevo el promedio y la desviacion estandar
     * basada en los datos para calcular y_hat (predicciones de los valores y,
     * segun el modelo)*/
    auto MuPromedio= extraer.Promedio(DataFrame);
    auto MuFeatures= MuPromedio(0,9);
    auto EscaladaData= DataFrame.rowwise()-DataFrame.colwise().mean();
    auto MuEstandar= extraer.DesvStandard(EscaladaData);
    auto DevFeatures= MuEstandar(0,9);
    Eigen::MatrixXd y_train_hat= (X_train*thetaOut*DevFeatures).array()+MuFeatures;
    Eigen::MatrixXd y= DataFrame.col(9).topRows(43152);

    /*A continuacion se determina que tan bueno es nuestro modelo
     * utilizando la metrica R2*/

    float ComprobacionMetrica= RL.MetricaR2(y, y_train_hat);
    std::cout<<"-----------METRICA DE RENDIMIENTO TRAIN------------"<<std::endl;
    std::cout<<ComprobacionMetrica<<std::endl;

    extraer.matrixToFile(y_train_hat, "Prediccion.txt");

    /*----------TEST----------*/
    /* Se define el vector theta, para pasar el alortimo del GD,
    * basicamento es un vector de 0 del mismo tamaño de entrenamiento,
    * adicional se declara alfa y el numero de iteraciones*/
    Eigen::VectorXd vectorThetaT = Eigen::VectorXd::Zero(X_test.cols());


    Eigen::VectorXd thetaOutT;
    std::vector<float>costoT;


    std::tuple<Eigen::VectorXd, std::vector<float>> salidaGDT = RL.Gradiente(X_test, y_test,vectorThetaT,alfa,iterator);
    std::tie(thetaOutT, costoT) = salidaGDT;
    /* std::cout<<thetaOut<<std::endl; */

    /* Se quiere observar como decrese la función de costo */
    /*for(auto v: costo){
    std::cout<<v<<std::endl;
    }*/

    /* Acontinuación por propositos de seguridad se exportan el vector de costo y el
     * vector theta a ficheros*/
    extraer.vectorToFile(costoT, "vectorCostoT.txt");
    extraer.matrixToFile(thetaOutT, "vectorThetaT.txt");

    auto MuPromedioT= extraer.Promedio(DataFrame);
    auto MuFeaturesT= MuPromedioT(0,9);
    auto EscaladaDataT= DataFrame.rowwise()-DataFrame.colwise().mean();
    auto MuEstandarT= extraer.DesvStandard(EscaladaDataT);
    auto DevFeaturesT= MuEstandarT(0,9);
    Eigen::MatrixXd y_hat_T= (X_test*thetaOutT*DevFeaturesT).array()+MuFeaturesT;
    Eigen::MatrixXd y_t= DataFrame.col(9).bottomRows(10788);

    /*A continuacion se determina que tan bueno es nuestro modelo
    * utilizando la metrica R2*/
    float ComprobacionMetricaT= RL.MetricaR2(y_t, y_hat_T);

    std::cout<<"-----------METRICA DE RENDIMIENTO TEST---------"<<std::endl;
    std::cout<<ComprobacionMetricaT<<std::endl;

    extraer.matrixToFile(y_hat_T, "PrediccionT.txt");


    return EXIT_SUCCESS;
}
