#include "regresionlineal.h"
#include <eigen3/Eigen/Dense>
#include <vector>
#include <cmath>
#include <iostream>

/*Se necesita entrenar un modelo, lo que implica minizar alguna
 * funcion de costo. De esta forma se puede medir la funcion
 * de hipotesis. Una funcion de costo es la forma de penalizar al
 * modelo por cometer un error.
 * Se implementa una funcion de tipo float  que toma como entrada
 * los valores (X,y)*/

float RegresionLineal::OLS_costo(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd Theta){
    Eigen::MatrixXd Diferencia= pow((X*Theta-y).array(),2);
    return (Diferencia.sum()/2*X.rows());
}

/* Se provee al programa una funcion para dar al algoritmo un valor inicial para
 * Theta el cual cambiara iteratibamente hasta que converga al valor minimo de la
 * funcion de costo. Basicamente describe el Gradiente Descendiente: La idea es calcular
 * el gradiente para la funcion de costo dado por la derivada parcial de la
 * funcion. La funcion debe tener un Alfa que representa el salto del gradiente.
 * Las entradas para la funcion son X, y, Theta */

std::tuple <Eigen::VectorXd, std::vector<float>> RegresionLineal::Gradiente(Eigen::MatrixXd X,Eigen::MatrixXd y,Eigen::VectorXd Theta,float alfa, int iterator){

    /*Se almacenan los parametros de theta */
    Eigen::MatrixXd temporal=Theta;
    /*Se captura el numero de features o variables independientes */
    int parametros=Theta.rows();
    /*Se ubica el costo inicial que se actualiza cada vez con los nuevos pesos (pendientes)*/
    std::vector<float> costo;
    costo.push_back(OLS_costo(X,y,Theta));

    /* Por cada iteracion se calcula la funcion de error de cada features o variable
     * independiente para ser almacenado en la variable temporal(tempTheta), basada en el
     * nuevo valor de Theta*/
    for(int i=0;i<iterator;++i){
        Eigen::MatrixXd error= X*Theta-y;
        for(int j=0;j<parametros;++j){
            Eigen::MatrixXd X_i= X.col(j);
            Eigen::MatrixXd tempTheta = error.cwiseProduct(X_i);
            temporal(j,0) = Theta(j,0)-((alfa/X.rows())*tempTheta.sum());
        }
        Theta= temporal;
        costo.push_back(OLS_costo(X,y,Theta));
    }
    /*Se empaqueta la tupla y se retorna*/
    return std::make_tuple(Theta, costo);
}

/*Para determinar que tan bueno es nuestro modelo es necesario
 * recurrir a una metrica de rendimiento. Para ello se escoge el
 * R2 el cual representa que tan bueno es nuestro modelo*/

float RegresionLineal::MetricaR2(Eigen::MatrixXd y,Eigen::MatrixXd y_hat){

    auto Numerador= pow((y-y_hat).array(),2).sum();
    auto Denominador= pow(y.array()-y.mean(),2).sum();

    return 1-Numerador/Denominador;
}


















