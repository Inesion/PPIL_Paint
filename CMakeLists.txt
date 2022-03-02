cmake_minimum_required(VERSION 3.10)

project(PPIL_Paint VERSION 1.0)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_subdirectory(src)