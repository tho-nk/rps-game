cmake_minimum_required(VERSION 3.10)
project(R_P_S)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)

set(PROJECT_SRC main.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

target_link_libraries(
  ${PROJECT_NAME} pthread rps::game_rps)

