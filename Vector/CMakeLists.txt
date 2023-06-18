cmake_minimum_required(VERSION 3.5.1)


add_library(vector Vector.c Vector.h)

project(Vector)
add_library(
        ${PROJECT_NAME}
        Vector.c

        Vector.h
)


