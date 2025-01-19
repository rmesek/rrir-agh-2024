cmake_minimum_required(VERSION 3.10)

project(ElasticDeformationSolver C)

set(CMAKE_C_STANDARD 11)

# Dodanie głównego pliku źródłowego
add_executable(elastic_solver src/main.c src/solver.c src/quadrature.c src/utils.c)

# Włączenie ścieżki do plików nagłówkowych
include_directories(${PROJECT_SOURCE_DIR}/include)

# Dodanie flag kompilatora
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")
