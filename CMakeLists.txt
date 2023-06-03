cmake_minimum_required(VERSION 3.12)

project(
    SimplexGraphics
    VERSION 0.1.0
    LANGUAGES CXX
)


set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(GLOBAL PROPERTY CXX_STANDARD 17)

add_library(
    ${PROJECT_NAME} SHARED
    src/Core.cpp
)
add_library(Simplex::Graphics ALIAS ${PROJECT_NAME})

# Create the export macro
include(GenerateExportHeader)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_CAPS)
generate_export_header(
    ${PROJECT_NAME}
    BASE_NAME ${PROJECT_NAME}
    EXPORT_MACRO_NAME "${PROJECT_NAME_CAPS}_EXPORT"
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} Simplex::Common)

