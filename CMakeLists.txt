cmake_minimum_required(VERSION 3.10)
project(Assignment-RPS LANGUAGES C CXX)

# Default Build Type to be Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# System dependencies
set(CMAKE_FOLDER "third-party")

add_subdirectory(rps)
add_subdirectory(test/gtest/rps/src)
