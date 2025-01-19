cmake_minimum_required(VERSION 3.10)
project(elastic_deformation)

find_package(GSL REQUIRED)

add_executable(elastic_solver src/main.c)
target_link_libraries(elastic_solver m GSL::gsl GSL::gslcblas)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")