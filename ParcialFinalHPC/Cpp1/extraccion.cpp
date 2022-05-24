#include "extraccion.h"

#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <fstream>
#include <boost/algorithm/string.hpp>

/* se implemente la primera funcion miembro: lectura
 * del fichero CSV. Para ello, disponemos de un vectro de vectores
 * del tipo string en donde se itera linea por linea y se almacena en el
 * vector de vectores del tipo string cada registro o fila */

using namespace std;

vector<vector<string>> ExtraccionData::ReadCSV()
{
    /* Se abre el fichero .csv de solo lectura */
    ifstream Fichero(setDatos);
    /* Se crea el vector de vectores a retornar tipo string,
 tendra los datos del dataset*/
    vector<vector<string>> datosString;
    /* Se itera a traves de cada linea. Se divide el contenido
     * segun el delimitador provisto por el constructor */
    string linea= ""; //variable para almacenar cada linea del dataset

    while(getline(Fichero,linea)){
        /* Cada linea se almacena en el vectorFila*/
        vector<string> vectorFila;
        /*cada vector se divide segun delimitador */
        boost::algorithm::split(vectorFila,linea,boost::is_any_of(delimitador));
        /*Cada fila ingresa al vector de vectores */
        datosString.push_back(vectorFila);
    }
    /* Se cierra el fichero */
    Fichero.close();
    return datosString;
}

/* segunda funcion miembro: almacenar el vector de vectroes de tipo String en una matrix.
 * La uidea es presentar el conjunto de datos similar a un objeto pandas (Dataframe) */

Eigen::MatrixXd ExtraccionData::CSVtoEigen(vector<vector<string>> setDatos, int filas, int columnas){

    /*identificar si tiene o no cabecera */
    if(header==true){

        filas=filas-1;
    }
    /* Se itera sobre filas y columnas para almacenar en la matrix de dimension filasXcolumnas.
     * Basicamente se almacenara strings del vector, luego se pasa a float para ser manipulados*/
    Eigen::MatrixXd dfMatriz(columnas,filas);
    int i,j;
    for(i=0;i<filas;i++){

        for(j=0;j<columnas;j++){
            dfMatriz(j,i)= atof(setDatos[i][j].c_str()); //Se almacena de tipo float

        }
    }
    /* Se transpone la matriz para ser retornada */
    return dfMatriz.transpose();
}

/* Se requiere implementar una funcion que calcule el primedio de los datos
 * (xColumnas). La funcion debe ser verificada con python usando cualquier biblioteca
 * (pandas, slearn, seabron...).
 * en C++, existe el tipo de dato "auto" -> "decltype".
 * En muchos casos, la herencia del tipo de dato no es evidente. El tipo de dato "auto" -> "decltype"
 * especifica el tipo de variable (deduce en tiempo de compilacion) que va a heredar la funcion.
 * Es decir, en la funcion, si el tipo de retorno es "auto", se evaluara mediante la expresion
 * para la deduccion del tipo de dato a retornar */

auto ExtraccionData::Promedio(Eigen::MatrixXd datos) ->
decltype(datos.colwise().mean()){

    return datos.colwise().mean();
}

/*Para implementar la funcion de desviacion estandar
 * datos = xi - x.promedio()
 * En esta funcion*/
auto ExtraccionData::DesvStandard(Eigen::MatrixXd datos) -> decltype(((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt()){

    return ((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt();
}

/*Se implementa la funcion que calcule la normalizacion
 * de los datos. lo anterior para regular la escala o magnitud de los datos.
 * Por lo tanto, asegurar la precision de los modelos de Machine Learning*/

Eigen::MatrixXd ExtraccionData::Normalizador(Eigen::MatrixXd datos){
    Eigen::MatrixXd datosEsc = datos.rowwise() - Promedio(datos);

    Eigen::MatrixXd NormMatriz = datosEsc.array().rowwise()/DesvStandard(datosEsc);
    return NormMatriz;
}

/* A continuacion se implementa la funcion para hacer la
 * division de datos en dos grupos. eñ primer grupo es para
 * entrenamiento, por lo general se usa del 70% al 80% del
 * total de los datos. El segundo grupo de datos, es para
 * pruebas. Se requiere crear una funcion que devuelva dos
 * grupos de datos, seleccionados de forma aleatoria */

std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> ExtraccionData::TrainTestDiv(Eigen::MatrixXd datos, float sizeTrain){

    int filas=datos.rows();
    int filasTrain= round(sizeTrain*filas);
    int filasTest = filas-filasTrain;

    /* Con Eigen se puede especificar un bloque de una matrix,
     * seleccionando las filas superiores para el conjunto de entrenamiento
     * y las demas para le conjunto de pruebas */
    Eigen::MatrixXd trainMatriz= datos.topRows(filasTrain);

    /* Una vez seleccionadas las filas superiores para entrenamiento,
     * se seleccionan las columnas a la izquierda (OJO: para este conjunto de datos)
     * correspondientes a las "features" o variables dependientes.
     * Entonces se selecciona la cantidad de columnas -1. */
    Eigen::MatrixXd x_train = trainMatriz.leftCols(datos.cols()-1);

    /* Se selecciona la variable dependiente, en los campos de
     * entrenamiento */
    Eigen::MatrixXd y_train= trainMatriz.rightCols(1);

    /* Se realiza el mismo procedimiento para el conjunto
     * de datos de prueba, recordando que se tienen los datos de la parte inferior
     * de la matriz de entrada. La funcion bottomRows devuelve la parte
     * inferior de la matriz */
    Eigen::MatrixXd testMatriz= datos.bottomRows(filasTest);
    Eigen::MatrixXd X_test = testMatriz.leftCols(datos.cols()-1);
    Eigen::MatrixXd Y_test = testMatriz.rightCols(1);

    /* finsalmente se retora la tupla, que contiene los
     * subconjintos de entrenamiento y de prueba, ATENCION:
     * con la tupla enviada, dado que al ser usada es necesario DESEMPAQUETARLA */
    return std::make_tuple (x_train, y_train, X_test, Y_test );
}

/*A continuacion se implementa una funcion para exportar los valores de vector a archivo*/
void ExtraccionData::vectorToFile(std::vector<float> vectorData, std::string nameFile){

    /* Se crea la salida de datos stream o flujo de datos, del fichero de entrada */
    std::ofstream salidaData(nameFile);
    /*se escribe cada objeto del tipo float sobre dataVector, condicionado por un cambio
     * de linea*/
    std::ostream_iterator<float> DataVector(salidaData, "\n");
    /*se hace una copia de los objetos escritos sobre el DataVector */
    std::copy(vectorData.begin(),vectorData.end(), DataVector);

}

    /*A continuacion se implementa una funcion para exportar una matrix dinamica
     * double de tipo Eigen a un fichero.
     * La exportaciones a ficheros son criticas o significativas,
     * En tanto se tiene seguridad, trazabilidad y control sobre los resultados parciales
     * obtenidos. */

void ExtraccionData::matrixToFile(Eigen::MatrixXd DataMatrix, std::string nameFile){
    /* Se crea la salida de datos stream o flujo de datos, del fichero de entrada */
    std::ofstream salidaData(nameFile);
    /* Si el fichero esta abierto, y no ha llegado al final copie los datos de la
     * matrix */
    if(salidaData.is_open()){
        salidaData << DataMatrix << "\n";
    }
}

/*WARNING: SE HA DE ESTUDIAR LOS DATOS PARA SABER LAS POSICIONES SOBRE LAS COLUMNAS:
 * VARIABLE DEPENDIENTE/VARIABLES INDEPENDIENTES */

