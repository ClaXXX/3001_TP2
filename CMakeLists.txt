cmake_minimum_required(VERSION 3.17)
project(question1)

find_package(Matplot++ CONFIG REQUIRED)

set(SRC
        question1.cpp
        main.cpp
        )

set(INCLUDE
        question1.hpp)

add_executable(question1 ${SRC} ${INCLUDE})
target_link_libraries(question1 Matplot++::matplot)