#ifndef EXTRACCION_H
#define EXTRACCION_H

#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <fstream>

/* Constructor de la clase para
 * los argumentos de entrada */

class ExtraccionData{
    /* nombre del fichero */
    std::string setDatos;
    /*Delimitador de CSV*/
    std::string delimitador;
    /*si tiene cabecera o no el CSV */
    bool header;

public:
    ExtraccionData(std::string datos,
                   std::string separador,
                   bool head):
    setDatos(datos),
    delimitador(separador),
    header(head){}
    /* prototipo de funciones de la clase */
    std::vector<std::vector<std::string>> ReadCSV();
    Eigen::MatrixXd CSVtoEigen(
            std::vector<std::vector<std::string>> setDatos, int filas, int columnas);

    auto Promedio(Eigen::MatrixXd datos) ->
    decltype(datos.colwise().mean());

    auto DesvStandard(Eigen::MatrixXd datos) -> decltype(((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt());

    Eigen::MatrixXd Normalizador(Eigen::MatrixXd datos);

    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd>  TrainTestDiv(Eigen::MatrixXd datos, float sizeTrain);
    void vectorToFile(std::vector<float> vectorData, std::string nameFile);
    void matrixToFile(Eigen::MatrixXd DataMatrix, std::string nameFile);
};

#endif // EXTRACCION_H
