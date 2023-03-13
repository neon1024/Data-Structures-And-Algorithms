cmake_minimum_required(VERSION 3.24)
project(Data_Structures_and_Algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(Assignments/A1)

add_executable(Data_Structures_and_Algorithms
        Assignments/A1/App.cpp
        Assignments/A1/Bag.cpp
        Assignments/A1/Bag.h
        Assignments/A1/BagIterator.cpp
        Assignments/A1/BagIterator.h
        Assignments/A1/ExtendedTest.cpp
        Assignments/A1/ExtendedTest.h
        Assignments/A1/ShortTest.cpp
        Assignments/A1/ShortTest.h)
