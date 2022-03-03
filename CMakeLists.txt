cmake_minimum_required(VERSION 3.3)

PROJECT(eigen_gmm)
set(Eigen3_DIR D:/ProgramFiles/Eigen3/share/eigen3/cmake)

find_package(Eigen3 REQUIRED)

INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})
aux_source_directory(./  SRC_LISTS)
add_executable(eigen_gmm eigen_gmm.cpp ${SRC_LISTS})
