cmake_minimum_required(VERSION 3.10.0)
project(sp1 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(milestones)
include_directories(utils)

add_subdirectory(milestones)
add_subdirectory(utils)

add_executable(sp1 main.cpp)

target_link_libraries(sp1 milestones utils)