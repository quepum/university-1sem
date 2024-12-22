cmake_minimum_required(VERSION 3.23)
project(HW4T2 C)

set(CMAKE_C_STANDARD 11)
add_executable(RepoGit1 hw10/main.c hw10/states.c hw10/list.c
        hw10/tests/tests.c
        hw10/tests/tests.h)
