cmake_minimum_required(VERSION 3.5)
include(FetchContent)

project(test_rate)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/..)

add_executable(test_rate)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_sources(
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/object.cpp
)

target_link_libraries(
    rate_limit
)
