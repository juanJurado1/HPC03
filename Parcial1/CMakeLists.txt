cmake_minimum_required(VERSION 3.5)

project(Parcial1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(project_sources
    main.cpp
    FUNCIONESMATRICIALES/funciones.cpp)
#variables que contienen la interface
set(project_headers
    FUNCIONESMATRICIALES/funciones.h)

#ejecutables
add_executable(${PROJECT_NAME}
    ${project_sources}
    ${project_headers})
