cmake_minimum_required(VERSION 3.15) 

set(PROJECT_NAME lab_6) 			 
project("${PROJECT_NAME}")        

set(CMAKE_CXX_STANDARD 20)

add_executable("${PROJECT_NAME}" StringUtils.cpp
        main.cpp)