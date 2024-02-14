cmake_minimum_required(VERSION 3.5)
include(FetchContent)

project(rate_limit)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_library(rate_limit)

find_package(Boost 1.83.0 REQUIRED)

target_include_directories(rate_limit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})

target_sources(rate_limit PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/rate_limit.cpp
)
