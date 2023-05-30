cmake_minimum_required(VERSION 3.24)
project(A5_1_Matrix)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(A5_1_Matrix
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Matrix.cpp
        Matrix.h
        ShortTest.cpp
        ShortTest.h MatrixIterator.cpp MatrixIterator.h)
