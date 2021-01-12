cmake_minimum_required(VERSION 3.17)
project(I_Proyecto_Estructuras)

set(CMAKE_CXX_STANDARD 14)

add_executable(I_Proyecto_Estructuras main.cpp ArbolABB.h ArbolABB.cpp Nodo.h PriorityQueue.cpp PriorityQueue.h CSVRead.h CSVWrite.h TransformadorCSV.h Cliente.cpp Cliente.h Cola.cpp Cola.h IReader.h IWriter.h Lista.cpp Lista.h)