#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <eigen3/Eigen/Dense>
#include <iostream>


class funciones{
        /*tamaño de la matriz */
        std::string tamano;
public:
    funciones(std::string tamanoMatriz):
        tamano(tamanoMatriz){}
    void funcionalidad(std::string tamanoMatriz);
    Eigen::Matrix3i MatrixA();
    Eigen::Matrix3i MatrixB();
    Eigen::Matrix3i Matrix2A();
    Eigen::Matrix3i MatrixI();
    Eigen::Matrix3i Potencia(Eigen::Matrix3i a, int b);
    Eigen::Matrix3i MatrixPotencia();
    Eigen::Matrix3d MatrixInversa();
    Eigen::MatrixXd MatrizEcuacionA();
    Eigen::MatrixXd MatrizEcuacionB();
    Eigen::MatrixXd MatrixProduccion();
    Eigen::MatrixXd MatrixCosto();
    Eigen::MatrixXd MatrixIncog();
    Eigen::MatrixXd MatrixIncog2();
    Eigen::MatrixXd MatrixIncog3();
    Eigen::MatrixXd MatrixIncog4();
};

#endif // FUNCIONES_H
