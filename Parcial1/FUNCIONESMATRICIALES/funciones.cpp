#include "funciones.h"
#include <iostream>
#include <eigen3/Eigen/Dense>

void funciones::funcionalidad(std::string tamanoMatriz)
{
    std::cout<<tamanoMatriz<<std::endl;
}

/* se declaran y se crean las matrices de 3 filas por 3 columnas con valores enteros */
Eigen::Matrix3i funciones::MatrixA(){
    Eigen::Matrix3i a;
    a << 2,0,1,
         3,0,0,
         5,1,1;
    return a;
}

Eigen::Matrix3i funciones::Matrix2A(){
    Eigen::Matrix3i a;
    a << 0,1,1,
         1,0,1,
         1,1,0;
    return a;
}

Eigen::Matrix3i funciones::MatrixB(){
    Eigen::Matrix3i a;
    a << 1,0,1,
         1,2,1,
         1,1,0;
    return a;
}

Eigen::Matrix3i funciones::MatrixI(){
    Eigen::Matrix3i a;
    a << 1,0,0,
         0,1,0,
         0,0,1;
    return a;
}

Eigen::Matrix3i funciones::MatrixPotencia(){
    Eigen::Matrix3i a;
    a << 1,0,1,
         0,1,0,
         0,0,1;
    return a;
}

Eigen::Matrix3i funciones::Potencia(Eigen::Matrix3i a, int b){
    if(b<1)
        throw;
    if(b==1)
        return a;
    return (a*Potencia(a, b-1));
}

Eigen::Matrix3d funciones::MatrixInversa(){
    Eigen::Matrix3d a;
    a << 1,-1,0,
         0,1,0,
         2,0,1;
    return a;
}

Eigen::MatrixXd funciones::MatrizEcuacionA(){
    Eigen::MatrixXd a(2,3);
    a << 1, 2, 2,
         -2, 1, 0;
    return a;
}

Eigen::MatrixXd funciones::MatrizEcuacionB(){
    Eigen::MatrixXd a(2,3);
    a << -4, -3, -2,
         -1, 0, -1;
    return a;
}

Eigen::MatrixXd funciones::MatrixProduccion(){
    Eigen::MatrixXd a(2,3);
    a << 400,200,50,
         300,100,30;
    return a;
}

Eigen::MatrixXd funciones::MatrixCosto(){
    Eigen::MatrixXd a(3,2);
    a << 25,1,
         30,1.2,
         33,1.3;
    return a;
}

Eigen::MatrixXd funciones::MatrixIncog(){
    Eigen::MatrixXd a(2,2);
    a << 1,1,
         3,4;
    return a;
}

Eigen::MatrixXd funciones::MatrixIncog2(){
    Eigen::MatrixXd a(2,2);
    a << 2,1,
         1,1;
    return a;
}

Eigen::MatrixXd funciones::MatrixIncog3(){
    Eigen::MatrixXd a(2,2);
    a << 1,2,
         1,3;
    return a;
}

Eigen::MatrixXd funciones::MatrixIncog4(){
    Eigen::MatrixXd a(2,2);
    a << 1,0,
         0,1;
    return a;
}
