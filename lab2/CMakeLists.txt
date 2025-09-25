cmake_minimum_required(VERSION 3.15) 

set(PROJECT_NAME lecture01_basics) 			 
project("${PROJECT_NAME}")        

set(CMAKE_CXX_STANDARD 20)

add_executable("${PROJECT_NAME}" lab2.cpp
        task_lab2.cpp)