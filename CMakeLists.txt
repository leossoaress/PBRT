cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3 -fopenmp")

file(GLOB SRC_FILES "src/*.h" "src/*.cpp")

set(SOURCE_FILES ${SRC_FILES})
add_executable(Raytracer ${SOURCE_FILES})

target_link_libraries(Raytracer "-lGL -lassimp -pthread")
