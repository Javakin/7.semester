# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/student/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/student/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FeatureExtraction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FeatureExtraction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FeatureExtraction.dir/flags.make

CMakeFiles/FeatureExtraction.dir/src/main.cpp.o: CMakeFiles/FeatureExtraction.dir/flags.make
CMakeFiles/FeatureExtraction.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FeatureExtraction.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FeatureExtraction.dir/src/main.cpp.o -c /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/src/main.cpp

CMakeFiles/FeatureExtraction.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FeatureExtraction.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/src/main.cpp > CMakeFiles/FeatureExtraction.dir/src/main.cpp.i

CMakeFiles/FeatureExtraction.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FeatureExtraction.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/src/main.cpp -o CMakeFiles/FeatureExtraction.dir/src/main.cpp.s

CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.requires

CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.provides: CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/FeatureExtraction.dir/build.make CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.provides

CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.provides.build: CMakeFiles/FeatureExtraction.dir/src/main.cpp.o


CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o: CMakeFiles/FeatureExtraction.dir/flags.make
CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o: ../src/Markers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o -c /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/src/Markers.cpp

CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/src/Markers.cpp > CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.i

CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/src/Markers.cpp -o CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.s

CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o.requires:

.PHONY : CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o.requires

CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o.provides: CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o.requires
	$(MAKE) -f CMakeFiles/FeatureExtraction.dir/build.make CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o.provides.build
.PHONY : CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o.provides

CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o.provides.build: CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o


# Object files for target FeatureExtraction
FeatureExtraction_OBJECTS = \
"CMakeFiles/FeatureExtraction.dir/src/main.cpp.o" \
"CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o"

# External object files for target FeatureExtraction
FeatureExtraction_EXTERNAL_OBJECTS =

FeatureExtraction: CMakeFiles/FeatureExtraction.dir/src/main.cpp.o
FeatureExtraction: CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o
FeatureExtraction: CMakeFiles/FeatureExtraction.dir/build.make
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_stitching3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_superres3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_videostab3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_aruco3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_bgsegm3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_bioinspired3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_ccalib3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_cvv3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_datasets3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_dpm3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_face3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_fuzzy3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_hdf3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_line_descriptor3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_optflow3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_plot3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_reg3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_saliency3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_stereo3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_structured_light3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_surface_matching3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_text3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_xfeatures2d3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_ximgproc3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_xobjdetect3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_xphoto3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_shape3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_video3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_viz3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_phase_unwrapping3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_rgbd3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_calib3d3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_features2d3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_flann3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_objdetect3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_ml3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_highgui3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_photo3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_videoio3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_imgcodecs3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_imgproc3.so.3.2.0
FeatureExtraction: /opt/ros/kinetic/lib/libopencv_core3.so.3.2.0
FeatureExtraction: CMakeFiles/FeatureExtraction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FeatureExtraction"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FeatureExtraction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FeatureExtraction.dir/build: FeatureExtraction

.PHONY : CMakeFiles/FeatureExtraction.dir/build

CMakeFiles/FeatureExtraction.dir/requires: CMakeFiles/FeatureExtraction.dir/src/main.cpp.o.requires
CMakeFiles/FeatureExtraction.dir/requires: CMakeFiles/FeatureExtraction.dir/src/Markers.cpp.o.requires

.PHONY : CMakeFiles/FeatureExtraction.dir/requires

CMakeFiles/FeatureExtraction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FeatureExtraction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FeatureExtraction.dir/clean

CMakeFiles/FeatureExtraction.dir/depend:
	cd /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/cmake-build-debug /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/cmake-build-debug /home/student/Desktop/7.semester/RoVi-finalProject/FeatureExtraction/cmake-build-debug/CMakeFiles/FeatureExtraction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FeatureExtraction.dir/depend

