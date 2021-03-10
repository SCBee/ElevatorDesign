cmake_minimum_required(VERSION 3.0.0)
project(design VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories( ${CMAKE_SOURCE_DIR}/include )

file(GLOB SRCS src/*.cpp)

add_executable(design main.cpp ${SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
