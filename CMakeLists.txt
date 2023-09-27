cmake_minimum_required(VERSION 3.26)
project(CSC402Project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSC402Project1 main.cpp
        Bank.cpp
        Account.cpp
        ATM.cpp
)
