cmake_minimum_required(VERSION 3.17)
project(question2)

set(SRC
        page.cpp
        resultat.cpp
        tests.cpp)

set(INCLUDE
        page.hpp
        resultat.hpp)

add_executable(question2 ${SRC} ${INCLUDE})