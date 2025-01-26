cmake_minimum_required(VERSION 3.25)
project(kursovaya)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLADS} -static-libstdc++ -static-libgcc")
add_executable(kursovaya main.cpp main.h actfile.cpp actfile.h acttable.cpp acttable.h main.cpp encrypt.cpp encrypt.h xcvbnm.cpp)
