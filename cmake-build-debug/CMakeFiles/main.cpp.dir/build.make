# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/leo/Downloads/clion-2017.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/leo/Downloads/clion-2017.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leo/Documents/UFPB/PBRT/Raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.cpp.dir/flags.make

CMakeFiles/main.cpp.dir/buffer.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/buffer.cpp.o: ../buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.cpp.dir/buffer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/buffer.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/buffer.cpp

CMakeFiles/main.cpp.dir/buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/buffer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/buffer.cpp > CMakeFiles/main.cpp.dir/buffer.cpp.i

CMakeFiles/main.cpp.dir/buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/buffer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/buffer.cpp -o CMakeFiles/main.cpp.dir/buffer.cpp.s

CMakeFiles/main.cpp.dir/buffer.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/buffer.cpp.o.requires

CMakeFiles/main.cpp.dir/buffer.cpp.o.provides: CMakeFiles/main.cpp.dir/buffer.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/buffer.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/buffer.cpp.o.provides

CMakeFiles/main.cpp.dir/buffer.cpp.o.provides.build: CMakeFiles/main.cpp.dir/buffer.cpp.o


CMakeFiles/main.cpp.dir/camera.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/camera.cpp.o: ../camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.cpp.dir/camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/camera.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/camera.cpp

CMakeFiles/main.cpp.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/camera.cpp > CMakeFiles/main.cpp.dir/camera.cpp.i

CMakeFiles/main.cpp.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/camera.cpp -o CMakeFiles/main.cpp.dir/camera.cpp.s

CMakeFiles/main.cpp.dir/camera.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/camera.cpp.o.requires

CMakeFiles/main.cpp.dir/camera.cpp.o.provides: CMakeFiles/main.cpp.dir/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/camera.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/camera.cpp.o.provides

CMakeFiles/main.cpp.dir/camera.cpp.o.provides.build: CMakeFiles/main.cpp.dir/camera.cpp.o


CMakeFiles/main.cpp.dir/diffuse.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/diffuse.cpp.o: ../diffuse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.cpp.dir/diffuse.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/diffuse.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/diffuse.cpp

CMakeFiles/main.cpp.dir/diffuse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/diffuse.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/diffuse.cpp > CMakeFiles/main.cpp.dir/diffuse.cpp.i

CMakeFiles/main.cpp.dir/diffuse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/diffuse.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/diffuse.cpp -o CMakeFiles/main.cpp.dir/diffuse.cpp.s

CMakeFiles/main.cpp.dir/diffuse.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/diffuse.cpp.o.requires

CMakeFiles/main.cpp.dir/diffuse.cpp.o.provides: CMakeFiles/main.cpp.dir/diffuse.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/diffuse.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/diffuse.cpp.o.provides

CMakeFiles/main.cpp.dir/diffuse.cpp.o.provides.build: CMakeFiles/main.cpp.dir/diffuse.cpp.o


CMakeFiles/main.cpp.dir/lightsource.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/lightsource.cpp.o: ../lightsource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.cpp.dir/lightsource.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/lightsource.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/lightsource.cpp

CMakeFiles/main.cpp.dir/lightsource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/lightsource.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/lightsource.cpp > CMakeFiles/main.cpp.dir/lightsource.cpp.i

CMakeFiles/main.cpp.dir/lightsource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/lightsource.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/lightsource.cpp -o CMakeFiles/main.cpp.dir/lightsource.cpp.s

CMakeFiles/main.cpp.dir/lightsource.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/lightsource.cpp.o.requires

CMakeFiles/main.cpp.dir/lightsource.cpp.o.provides: CMakeFiles/main.cpp.dir/lightsource.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/lightsource.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/lightsource.cpp.o.provides

CMakeFiles/main.cpp.dir/lightsource.cpp.o.provides.build: CMakeFiles/main.cpp.dir/lightsource.cpp.o


CMakeFiles/main.cpp.dir/material.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/material.cpp.o: ../material.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.cpp.dir/material.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/material.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/material.cpp

CMakeFiles/main.cpp.dir/material.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/material.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/material.cpp > CMakeFiles/main.cpp.dir/material.cpp.i

CMakeFiles/main.cpp.dir/material.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/material.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/material.cpp -o CMakeFiles/main.cpp.dir/material.cpp.s

CMakeFiles/main.cpp.dir/material.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/material.cpp.o.requires

CMakeFiles/main.cpp.dir/material.cpp.o.provides: CMakeFiles/main.cpp.dir/material.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/material.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/material.cpp.o.provides

CMakeFiles/main.cpp.dir/material.cpp.o.provides.build: CMakeFiles/main.cpp.dir/material.cpp.o


CMakeFiles/main.cpp.dir/onb.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/onb.cpp.o: ../onb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.cpp.dir/onb.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/onb.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/onb.cpp

CMakeFiles/main.cpp.dir/onb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/onb.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/onb.cpp > CMakeFiles/main.cpp.dir/onb.cpp.i

CMakeFiles/main.cpp.dir/onb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/onb.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/onb.cpp -o CMakeFiles/main.cpp.dir/onb.cpp.s

CMakeFiles/main.cpp.dir/onb.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/onb.cpp.o.requires

CMakeFiles/main.cpp.dir/onb.cpp.o.provides: CMakeFiles/main.cpp.dir/onb.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/onb.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/onb.cpp.o.provides

CMakeFiles/main.cpp.dir/onb.cpp.o.provides.build: CMakeFiles/main.cpp.dir/onb.cpp.o


CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o: ../orthographic_camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/orthographic_camera.cpp

CMakeFiles/main.cpp.dir/orthographic_camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/orthographic_camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/orthographic_camera.cpp > CMakeFiles/main.cpp.dir/orthographic_camera.cpp.i

CMakeFiles/main.cpp.dir/orthographic_camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/orthographic_camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/orthographic_camera.cpp -o CMakeFiles/main.cpp.dir/orthographic_camera.cpp.s

CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o.requires

CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o.provides: CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o.provides

CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o.provides.build: CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o


CMakeFiles/main.cpp.dir/perspective_camera.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/perspective_camera.cpp.o: ../perspective_camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.cpp.dir/perspective_camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/perspective_camera.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/perspective_camera.cpp

CMakeFiles/main.cpp.dir/perspective_camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/perspective_camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/perspective_camera.cpp > CMakeFiles/main.cpp.dir/perspective_camera.cpp.i

CMakeFiles/main.cpp.dir/perspective_camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/perspective_camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/perspective_camera.cpp -o CMakeFiles/main.cpp.dir/perspective_camera.cpp.s

CMakeFiles/main.cpp.dir/perspective_camera.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/perspective_camera.cpp.o.requires

CMakeFiles/main.cpp.dir/perspective_camera.cpp.o.provides: CMakeFiles/main.cpp.dir/perspective_camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/perspective_camera.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/perspective_camera.cpp.o.provides

CMakeFiles/main.cpp.dir/perspective_camera.cpp.o.provides.build: CMakeFiles/main.cpp.dir/perspective_camera.cpp.o


CMakeFiles/main.cpp.dir/primitive.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/primitive.cpp.o: ../primitive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.cpp.dir/primitive.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/primitive.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/primitive.cpp

CMakeFiles/main.cpp.dir/primitive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/primitive.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/primitive.cpp > CMakeFiles/main.cpp.dir/primitive.cpp.i

CMakeFiles/main.cpp.dir/primitive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/primitive.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/primitive.cpp -o CMakeFiles/main.cpp.dir/primitive.cpp.s

CMakeFiles/main.cpp.dir/primitive.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/primitive.cpp.o.requires

CMakeFiles/main.cpp.dir/primitive.cpp.o.provides: CMakeFiles/main.cpp.dir/primitive.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/primitive.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/primitive.cpp.o.provides

CMakeFiles/main.cpp.dir/primitive.cpp.o.provides.build: CMakeFiles/main.cpp.dir/primitive.cpp.o


CMakeFiles/main.cpp.dir/ray.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/ray.cpp.o: ../ray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/main.cpp.dir/ray.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/ray.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/ray.cpp

CMakeFiles/main.cpp.dir/ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/ray.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/ray.cpp > CMakeFiles/main.cpp.dir/ray.cpp.i

CMakeFiles/main.cpp.dir/ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/ray.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/ray.cpp -o CMakeFiles/main.cpp.dir/ray.cpp.s

CMakeFiles/main.cpp.dir/ray.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/ray.cpp.o.requires

CMakeFiles/main.cpp.dir/ray.cpp.o.provides: CMakeFiles/main.cpp.dir/ray.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/ray.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/ray.cpp.o.provides

CMakeFiles/main.cpp.dir/ray.cpp.o.provides.build: CMakeFiles/main.cpp.dir/ray.cpp.o


CMakeFiles/main.cpp.dir/raytracer.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/raytracer.cpp.o: ../raytracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/main.cpp.dir/raytracer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/raytracer.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/raytracer.cpp

CMakeFiles/main.cpp.dir/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/raytracer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/raytracer.cpp > CMakeFiles/main.cpp.dir/raytracer.cpp.i

CMakeFiles/main.cpp.dir/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/raytracer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/raytracer.cpp -o CMakeFiles/main.cpp.dir/raytracer.cpp.s

CMakeFiles/main.cpp.dir/raytracer.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/raytracer.cpp.o.requires

CMakeFiles/main.cpp.dir/raytracer.cpp.o.provides: CMakeFiles/main.cpp.dir/raytracer.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/raytracer.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/raytracer.cpp.o.provides

CMakeFiles/main.cpp.dir/raytracer.cpp.o.provides.build: CMakeFiles/main.cpp.dir/raytracer.cpp.o


CMakeFiles/main.cpp.dir/scene.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/scene.cpp.o: ../scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/main.cpp.dir/scene.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/scene.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/scene.cpp

CMakeFiles/main.cpp.dir/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/scene.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/scene.cpp > CMakeFiles/main.cpp.dir/scene.cpp.i

CMakeFiles/main.cpp.dir/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/scene.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/scene.cpp -o CMakeFiles/main.cpp.dir/scene.cpp.s

CMakeFiles/main.cpp.dir/scene.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/scene.cpp.o.requires

CMakeFiles/main.cpp.dir/scene.cpp.o.provides: CMakeFiles/main.cpp.dir/scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/scene.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/scene.cpp.o.provides

CMakeFiles/main.cpp.dir/scene.cpp.o.provides.build: CMakeFiles/main.cpp.dir/scene.cpp.o


CMakeFiles/main.cpp.dir/sphere.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/sphere.cpp.o: ../sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/main.cpp.dir/sphere.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/sphere.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/sphere.cpp

CMakeFiles/main.cpp.dir/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/sphere.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/sphere.cpp > CMakeFiles/main.cpp.dir/sphere.cpp.i

CMakeFiles/main.cpp.dir/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/sphere.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/sphere.cpp -o CMakeFiles/main.cpp.dir/sphere.cpp.s

CMakeFiles/main.cpp.dir/sphere.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/sphere.cpp.o.requires

CMakeFiles/main.cpp.dir/sphere.cpp.o.provides: CMakeFiles/main.cpp.dir/sphere.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/sphere.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/sphere.cpp.o.provides

CMakeFiles/main.cpp.dir/sphere.cpp.o.provides.build: CMakeFiles/main.cpp.dir/sphere.cpp.o


CMakeFiles/main.cpp.dir/triangle.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/triangle.cpp.o: ../triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/main.cpp.dir/triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/triangle.cpp.o -c /home/leo/Documents/UFPB/PBRT/Raytracer/triangle.cpp

CMakeFiles/main.cpp.dir/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leo/Documents/UFPB/PBRT/Raytracer/triangle.cpp > CMakeFiles/main.cpp.dir/triangle.cpp.i

CMakeFiles/main.cpp.dir/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leo/Documents/UFPB/PBRT/Raytracer/triangle.cpp -o CMakeFiles/main.cpp.dir/triangle.cpp.s

CMakeFiles/main.cpp.dir/triangle.cpp.o.requires:

.PHONY : CMakeFiles/main.cpp.dir/triangle.cpp.o.requires

CMakeFiles/main.cpp.dir/triangle.cpp.o.provides: CMakeFiles/main.cpp.dir/triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/triangle.cpp.o.provides.build
.PHONY : CMakeFiles/main.cpp.dir/triangle.cpp.o.provides

CMakeFiles/main.cpp.dir/triangle.cpp.o.provides.build: CMakeFiles/main.cpp.dir/triangle.cpp.o


# Object files for target main.cpp
main_cpp_OBJECTS = \
"CMakeFiles/main.cpp.dir/buffer.cpp.o" \
"CMakeFiles/main.cpp.dir/camera.cpp.o" \
"CMakeFiles/main.cpp.dir/diffuse.cpp.o" \
"CMakeFiles/main.cpp.dir/lightsource.cpp.o" \
"CMakeFiles/main.cpp.dir/material.cpp.o" \
"CMakeFiles/main.cpp.dir/onb.cpp.o" \
"CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o" \
"CMakeFiles/main.cpp.dir/perspective_camera.cpp.o" \
"CMakeFiles/main.cpp.dir/primitive.cpp.o" \
"CMakeFiles/main.cpp.dir/ray.cpp.o" \
"CMakeFiles/main.cpp.dir/raytracer.cpp.o" \
"CMakeFiles/main.cpp.dir/scene.cpp.o" \
"CMakeFiles/main.cpp.dir/sphere.cpp.o" \
"CMakeFiles/main.cpp.dir/triangle.cpp.o"

# External object files for target main.cpp
main_cpp_EXTERNAL_OBJECTS =

main.cpp: CMakeFiles/main.cpp.dir/buffer.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/camera.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/diffuse.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/lightsource.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/material.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/onb.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/perspective_camera.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/primitive.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/ray.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/raytracer.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/scene.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/sphere.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/triangle.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/build.make
main.cpp: CMakeFiles/main.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable main.cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.cpp.dir/build: main.cpp

.PHONY : CMakeFiles/main.cpp.dir/build

CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/buffer.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/camera.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/diffuse.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/lightsource.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/material.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/onb.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/orthographic_camera.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/perspective_camera.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/primitive.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/ray.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/raytracer.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/scene.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/sphere.cpp.o.requires
CMakeFiles/main.cpp.dir/requires: CMakeFiles/main.cpp.dir/triangle.cpp.o.requires

.PHONY : CMakeFiles/main.cpp.dir/requires

CMakeFiles/main.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.cpp.dir/clean

CMakeFiles/main.cpp.dir/depend:
	cd /home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leo/Documents/UFPB/PBRT/Raytracer /home/leo/Documents/UFPB/PBRT/Raytracer /home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug /home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug /home/leo/Documents/UFPB/PBRT/Raytracer/cmake-build-debug/CMakeFiles/main.cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.cpp.dir/depend

