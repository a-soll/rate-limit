cmake_minimum_required(VERSION 3.5)
include(FetchContent)

project(test_rate)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(test_rate)

find_package(Boost 1.83.0 REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS})

target_sources(test_rate PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/object.cpp
)

target_link_libraries(test_rate PUBLIC rate_limit)
