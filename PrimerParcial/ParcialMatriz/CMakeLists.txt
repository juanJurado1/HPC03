cmake_minimum_required(VERSION 3.5)

project(ParcialMatriz LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#variables que contienen la fuente
set(project_sources
    main.cpp
    FMATRIZ/funciones.cpp)
#variables que contienen la interface
set(project_headers
    FMATRIZ/funciones.h)

#ejecutables
add_executable(${PROJECT_NAME}
    ${project_sources}
    ${project_headers})
