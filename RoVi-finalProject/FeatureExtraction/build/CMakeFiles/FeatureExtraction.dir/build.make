# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/build

# Include any dependencies generated for this target.
include CMakeFiles/FeatureExtraction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FeatureExtraction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FeatureExtraction.dir/flags.make

CMakeFiles/FeatureExtraction.dir/src/main.cpp.o: CMakeFiles/FeatureExtraction.dir/flags.make
CMakeFiles/FeatureExtraction.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FeatureExtraction.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FeatureExtraction.dir/src/main.cpp.o -c /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/src/main.cpp

CMakeFiles/FeatureExtraction.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FeatureExtraction.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/src/main.cpp > CMakeFiles/FeatureExtraction.dir/src/main.cpp.i

CMakeFiles/FeatureExtraction.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FeatureExtraction.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/src/main.cpp -o CMakeFiles/FeatureExtraction.dir/src/main.cpp.s

CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.requires

CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.provides: CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/FeatureExtraction.dir/build.make CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.provides

CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.provides.build: CMakeFiles/FeatureExtraction.dir/src/main.cpp.o


# Object files for target FeatureExtraction
FeatureExtraction_OBJECTS = \
"CMakeFiles/FeatureExtraction.dir/src/main.cpp.o"

# External object files for target FeatureExtraction
FeatureExtraction_EXTERNAL_OBJECTS =

FeatureExtraction: CMakeFiles/FeatureExtraction.dir/src/main.cpp.o
FeatureExtraction: CMakeFiles/FeatureExtraction.dir/build.make
FeatureExtraction: /usr/local/lib/libopencv_shape.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_stitching.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_superres.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_videostab.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_viz.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_objdetect.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_calib3d.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_features2d.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_flann.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_highgui.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_ml.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_photo.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_video.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_videoio.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_imgproc.so.3.2.0
FeatureExtraction: /usr/local/lib/libopencv_core.so.3.2.0
FeatureExtraction: CMakeFiles/FeatureExtraction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FeatureExtraction"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FeatureExtraction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FeatureExtraction.dir/build: FeatureExtraction

.PHONY : CMakeFiles/FeatureExtraction.dir/build

CMakeFiles/FeatureExtraction.dir/requires: CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/FeatureExtraction.dir/requires

CMakeFiles/FeatureExtraction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FeatureExtraction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FeatureExtraction.dir/clean

CMakeFiles/FeatureExtraction.dir/depend:
	cd /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/build /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/build /home/tera/Desktop/7.semester.git/RoVi-finalProject/FeatureExtraction/build/CMakeFiles/FeatureExtraction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FeatureExtraction.dir/depend
