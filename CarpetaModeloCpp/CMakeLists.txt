cmake_minimum_required(VERSION 3.5)

project(ModeloLR LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(project_sources
    main.cpp
    regresionlineal.cpp
    EXTRACCION/extraccion.cpp)

set(project_headers
    regresionlineal.h
    EXTRACCION/extraccion.h)


add_executable(${PROJECT_NAME}
                ${project_sources}
                ${project_headers})
