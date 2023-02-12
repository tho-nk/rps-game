cmake_minimum_required(VERSION 3.10)

project(game_rps)

file(GLOB SOURCES "*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(${PROJECT_NAME} ${SOURCES})

add_library(rps::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
