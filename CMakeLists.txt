cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3 -fopenmp")

set(SOURCE_FILES main.cpp main.h buffer.cpp buffer.h camera.cpp camera.h diffuse.cpp diffuse.h intersection_record.h lightsource.cpp lightsource.h material.cpp material.h onb.cpp onb.h orthographic_camera.cpp orthographic_camera.h perspective_camera.cpp perspective_camera.h primitive.cpp primitive.h ray.cpp ray.h raytracer.cpp raytracer.h scene.cpp scene.h sphere.cpp sphere.h triangle.cpp triangle.h mirror.cpp mirror.h smooth_dielectric.cpp smooth_dielectric.h bbox.h bbox.cpp bvh.h bvh.cpp cook_torrance.h cook_torrance.cpp)
add_executable(Raytracer ${SOURCE_FILES})

target_link_libraries(Raytracer "-lGL -lassimp -pthread")
