#include <iostream>
#include "FUNCIONESMATRICIALES/funciones.h"
#include <eigen3/Eigen/Dense>

/*******************************************
 * Autor: Juan Pablo Jurado Muñoz
 * Fecha: 12/03/2022
 * Materia: HPC-03
 * Ciencias de la computacion e Inteligencia Artificial
 * Universidad Sergio Arboleda
 * Primer Parcial HPC (funciones Matriciales)
 *******************************************/

typedef Eigen::Matrix<double,2,3> Matrix23d;
typedef Eigen::Matrix<double,3,2> Matrix32d;
typedef Eigen::Matrix<double,3,4> Matrix34d;
typedef Eigen::Matrix<double,2,2> Matrix22d;

int main(){

    int b;

    funciones a("1");

    /* se inicializan las matrices asignandoles el valor de MatrizA y MAtrizB */
    Eigen::Matrix3i MatrizA= a.MatrixA();
    Eigen::Matrix3i MatrizB= a.MatrixB();
    Eigen::Matrix3i Matriz2A= a.Matrix2A();
    Eigen::Matrix3i MatrizI= a.MatrixI();
    Eigen::Matrix3i MatrizPot= a.MatrixPotencia();
    Eigen::Matrix3d MatrizInv= a.MatrixInversa();
    Matrix23d MatrizEcuA= a.MatrizEcuacionA();
    Matrix23d MatrizEcuB= a.MatrizEcuacionB();
    Matrix23d MatrizPro= a.MatrixProduccion();
    Matrix32d MatrizCos= a.MatrixCosto();
    Matrix22d MatrizAincog= a.MatrixIncog();
    Matrix22d MatrizBincog= a.MatrixIncog2();
    Matrix22d MatrizCincog= a.MatrixIncog3();
    Matrix22d MatrizIincog= a.MatrixIncog4();
    int opc=0;
    do
    {
        int opc1=0;
        int opc2=0;
        int opc3=0;
        int opc4=0;
        std::cout<<"BIENVENIDO A SU MENU DE OPCIONES"<<std::endl;
        /*menu de opciones */
        std::cout<<"1. Operaciones basicas con matrices"<<std::endl;
        std::cout<<"2. Realiza la siguiente demostracion"<<std::endl;
        std::cout<<"3. n-esima potencia de la matriz"<<std::endl;
        std::cout<<"4. Matriz inversa"<<std::endl;
        std::cout<<"5. Sistema de ecuaciones con matrices"<<std::endl;
        std::cout<<"6. Analisis de problemas usando matrices"<<std::endl;
        std::cout<<"7. Ecuaciones de una incognita en matrices"<<std::endl;
        std::cout<<"8. Salir"<<std::endl;
        std::cout<<"ingrerse la operacion que desea realizar"<<std::endl;
        std::cin>>opc1;

        switch(opc1) //donde opc es la variable a comparar
        {
            case 1: //Bloque de instrucciones 1 para menu principal
            std::cout<<"OPERACIONES BASICAS CON MATRICES"<<std::endl;
            std::cout<<"1. A+B"<<std::endl;
            std::cout<<"2. A-B"<<std::endl;
            std::cout<<"3. A.B"<<std::endl;
            std::cout<<"4. B.A"<<std::endl;
            std::cout<<"5. A⁽⁻¹⁾"<<std::endl;
            std::cin>>opc2;
                switch(opc2){
                    case 1: //Bloque de instrucciones 1 para operacion con matrices
                    std::cout<<"El resultado de la suma matricial es: \n"<<std::endl;
                    std::cout<<MatrizA+MatrizB<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    break;
                    case 2:
                    std::cout<<"El resultado de la resta matricial es: \n"<<std::endl;
                    std::cout<<MatrizA-MatrizB<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    break;
                    case 3:
                    std::cout<<"El resultado de la multiplicacion matricial es: \n"<<std::endl;
                    std::cout<<MatrizA*MatrizB<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    break;
                    case 4:
                    std::cout<<"El resultado de la multiplicacion matricial es: \n"<<std::endl;
                    std::cout<<MatrizB*MatrizA<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    break;
                    case 5:
                    std::cout<<"El resultado de la transpuesta matricial es: \n"<<std::endl;
                    std::cout<<MatrizA.transpose()<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    break;
                    default:
                        std::cout<<"seleccion incorrecta"<<std::endl;
                    }
            break;

            case 2://Bloque de instrucciones 2 para menu principal
            std::cout<<"COMPROBACION DE LA DEMOSTRACION"<<std::endl;
            std::cout<<"Elevamos la matriz A al cuadrado \n";
            std::cout<<Matriz2A*Matriz2A<<std::endl;
            std::cout<<"Sustituimos en la parte izquierda de la ecuación y calculamos \n";
            std::cout<<(Matriz2A*Matriz2A)-Matriz2A-2*MatrizI<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            break;

            case 3://Bloque de instrucciones 3 para menu principal
            std::cout<<"N-ESIMA POTENCIA DE LA MATRIZ"<<std::endl;
            std::cout<<"Ingrese la potencia al a que desea elevar la matriz: ";
            std::cin>>b;
            std::cout<<a.Potencia(MatrizPot,b)<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            break;

            case 4://Bloque de instrucciones 4 para menu principal
            std::cout<<"INVERSA DE LA MATRIZ"<<std::endl;
            std::cout<<MatrizInv.inverse()<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            break;

            case 5://Bloque de instrucciones 5 para menu principal
            std::cout<<"SISTEMA DE ECUACIONES CON MATRICES"<<std::endl;
            std::cout<<"Matriz de la primera ecuacion"<<std::endl;
            std::cout<<MatrizEcuA<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"Matriz de la segunda ecuacion"<<std::endl;
            std::cout<<MatrizEcuB<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"Multiplicamos la segunda ecuacion por -2"<<std::endl;
            std::cout<<MatrizEcuB*(-2)<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"Sumamos miembro a miembro y resolvemos para B"<<std::endl;
            std::cout<<MatrizEcuA+(MatrizEcuB*-2)<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"Despejamos B"<<std::endl;
            std::cout<<(MatrizEcuA+(MatrizEcuB*-2))/7<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"Multiplicamos la primera ecuacion por 3 y sumamos miembro a miembro"<<std::endl;
            std::cout<<(MatrizEcuA*3)+MatrizEcuB<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"Despejamos A"<<std::endl;
            std::cout<<((MatrizEcuA*3)+MatrizEcuB)/7<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"RESULTADO FINAL"<<std::endl;
            std::cout<<(MatrizEcuA+(MatrizEcuB*-2))/7<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            break;

            case 6://Bloque de instrucciones 6 para menu principal
            std::cout<<"ANALISIS DE PROBLEMAS USANDO MATRICES"<<std::endl;
            std::cout<<"Matriz de produccion"<<std::endl;
            std::cout<<MatrizPro<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"Matriz de costo"<<std::endl;
            std::cout<<MatrizCos<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            std::cout<<"Matriz que expresa las horas de taller y de administración para cada uno de los modelos"<<std::endl;
            std::cout<<MatrizPro*MatrizCos<<std::endl;
            std::cout<<"******************************************"<<std::endl;
            break;
            case 7://Bloque de instrucciones 7 para menu principal
                std::cout<<"ECUACIONES DE UNA INCOGNITA EN MATRICES"<<std::endl;
                std::cout<<"1. XA=B+I"<<std::endl;
                std::cout<<"2. AX+B=C"<<std::endl;
                std::cout<<"3. AX+B=2C"<<std::endl;
                std::cout<<"4. AX+BX=C"<<std::endl;
                std::cout<<"5. XAB-XC=2C"<<std::endl;
                std::cout<<"ingrese la operacion que desea realizar"<<std::endl;
                std::cin>>opc4;
            switch(opc4){
                case 1:
                    std::cout<<"Matriz A"<<std::endl;
                    std::cout<<MatrizAincog<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    std::cout<<"Matriz B"<<std::endl;
                    std::cout<<MatrizBincog<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    std::cout<<"Matriz C"<<std::endl;
                    std::cout<<MatrizCincog<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    std::cout<<"X= (B+I)*A⁽⁻¹⁾"<<std::endl;
                    std::cout<<(MatrizBincog+MatrizIincog)*MatrizAincog.inverse()<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    std::cout<<"X= (B+I)*A⁽⁻¹⁾"<<std::endl;
                    std::cout<<(MatrizBincog+MatrizIincog)*MatrizAincog.inverse()<<std::endl;
                    std::cout<<"******************************************"<<std::endl;
                    break;
                case 2:
                std::cout<<"X= A⁽⁻¹⁾(C-B)"<<std::endl;
                std::cout<<MatrizAincog.inverse()*(MatrizCincog-MatrizBincog)<<std::endl;
                std::cout<<"******************************************"<<std::endl;
                    break;
                case 3:
                std::cout<<"X=(2C-B)A⁽⁻¹⁾"<<std::endl;
                std::cout<<(2*MatrizCincog-MatrizBincog)*MatrizAincog.inverse()<<std::endl;
                std::cout<<"******************************************"<<std::endl;
                    break;
                case 4:
                std::cout<<"X= (A+B)⁽⁻¹⁾*C"<<std::endl;
                std::cout<<(MatrizAincog+MatrizBincog).inverse()*MatrizCincog<<std::endl;
                std::cout<<"******************************************"<<std::endl;
                    break;
                case 5:
                std::cout<<"X= 2C*(AB-C)⁽⁻¹⁾"<<std::endl;
                std::cout<<2*MatrizCincog*(MatrizAincog*MatrizBincog-MatrizCincog).inverse()<<std::endl;
                std::cout<<"******************************************"<<std::endl;
                    break;
                default:
                    std::cout<<"seleccion incorrecta"<<std::endl;
            }
            case 8://Bloque de instrucciones 8 para menu principal
                opc=1;
            break;

            default: //Bloque de instrucciones por defecto;
                std::cout<<"seleccion incorrecta"<<std::endl;
        }
    }
    while(opc==0);
    return 0;
}
