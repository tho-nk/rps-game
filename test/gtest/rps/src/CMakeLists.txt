cmake_minimum_required(VERSION 3.7)
project(runTest)

message("currentDir = ${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include
                    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../rps/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/../../../../third-party/googletest/include)


file(GLOB SOURCES "*.cpp")

add_executable(${PROJECT_NAME}
    ${SOURCES})

target_link_libraries(${PROJECT_NAME}
                        rps::game_rps
                        -L${CMAKE_CURRENT_SOURCE_DIR}/../../../../third-party/googletest/lib gtest gmock gtest_main
                        -lpthread)
    
