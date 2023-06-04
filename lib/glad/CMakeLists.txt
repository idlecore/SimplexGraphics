cmake_minimum_required(VERSION 3.12)

project(
    glad
    VERSION 0.1.0
    LANGUAGES CXX
)


add_library(
    ${PROJECT_NAME} STATIC
    src/glad.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include)