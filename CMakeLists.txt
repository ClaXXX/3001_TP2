cmake_minimum_required(VERSION 3.17)
project(question4)

set(SRC
        jeu.cpp
        monstre.cpp
        tests.cpp
        )

set(INCLUDE
        .
        )

add_executable(question4 ${SRC} ${INCLUDE})