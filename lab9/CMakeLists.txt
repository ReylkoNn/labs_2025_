cmake_minimum_required(VERSION 3.10)
project(EventList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(event_list
    src/main.cpp
    src/event_list.cpp
        src/event_list.cpp
    include/event_list.h
)