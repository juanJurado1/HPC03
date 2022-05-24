#ifndef REGRESIONLINEAL_H
#define REGRESIONLINEAL_H
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

class RegresionLineal
{
public:
    RegresionLineal()
    {}

    /*A continuacion se implementa la funcion de minimos cuadrados
     * ordinarios como funcion de costo */
    float OLS_costo(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd Theta);

    std::tuple <Eigen::VectorXd, std::vector<float>> Gradiente(Eigen::MatrixXd X,Eigen::MatrixXd y,Eigen::VectorXd Theta,float alfa,int iterator);

    float MetricaR2(Eigen::MatrixXd y,Eigen::MatrixXd y_hat);
};

#endif // REGRESIONLINEAL_H
