cmake_minimum_required(VERSION 3.7)

#set(CMAKE_CXX_STANDARD 11 -fopenmp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES main.cpp main.h buffer.cpp buffer.h camera.cpp camera.h diffuse.cpp diffuse.h intersection_record.h lightsource.cpp lightsource.h material.cpp material.h onb.cpp onb.h orthographic_camera.cpp orthographic_camera.h perspective_camera.cpp perspective_camera.h primitive.cpp primitive.h ray.cpp ray.h raytracer.cpp raytracer.h scene.cpp scene.h sphere.cpp sphere.h triangle.cpp triangle.h mirror.cpp mirror.h)
add_executable(Raytracer ${SOURCE_FILES})

set(ASSIMP_DIR "/home/leo/Documents/UFPB/PBRT/Raytracer/assimp/cmake-modules")

set(CMAKE_MODULE_PATH "/home/leo/Documents/UFPB/PBRT/Raytracer/assimp/cmake-modules" ${CMAKE_MODULE_PATH})

find_package(ASSIMP REQUIRED system window graphics network audio)

if(ASSIMP_FOUND)
    include_directories(${ASSIMP_INCLUDE_DIR})
    target_link_libraries(Raytracer ${ASSIMP_LIBRARIES})
endif()

