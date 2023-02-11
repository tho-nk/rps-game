cmake_minimum_required(VERSION 3.7)
project(test_rps)

message("currentDir = ${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../rps/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/../../../third-party/googletest/include)


file(GLOB SOURCES "*.cpp")

add_executable(${PROJECT_NAME}
    ${SOURCES})

target_link_libraries(${PROJECT_NAME}
                        -L${CMAKE_CURRENT_SOURCE_DIR}/../../../third-party/googletest/lib gtest gtest_main
                        -lpthread)
    
