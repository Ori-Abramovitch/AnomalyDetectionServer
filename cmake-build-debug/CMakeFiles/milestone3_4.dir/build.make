# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/189/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/189/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ori/CLionProjects/milestone3.4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ori/CLionProjects/milestone3.4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/milestone3_4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/milestone3_4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/milestone3_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/milestone3_4.dir/flags.make

CMakeFiles/milestone3_4.dir/MainTrain.cpp.o: CMakeFiles/milestone3_4.dir/flags.make
CMakeFiles/milestone3_4.dir/MainTrain.cpp.o: ../MainTrain.cpp
CMakeFiles/milestone3_4.dir/MainTrain.cpp.o: CMakeFiles/milestone3_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/milestone3_4.dir/MainTrain.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/milestone3_4.dir/MainTrain.cpp.o -MF CMakeFiles/milestone3_4.dir/MainTrain.cpp.o.d -o CMakeFiles/milestone3_4.dir/MainTrain.cpp.o -c /home/ori/CLionProjects/milestone3.4/MainTrain.cpp

CMakeFiles/milestone3_4.dir/MainTrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone3_4.dir/MainTrain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ori/CLionProjects/milestone3.4/MainTrain.cpp > CMakeFiles/milestone3_4.dir/MainTrain.cpp.i

CMakeFiles/milestone3_4.dir/MainTrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone3_4.dir/MainTrain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ori/CLionProjects/milestone3.4/MainTrain.cpp -o CMakeFiles/milestone3_4.dir/MainTrain.cpp.s

CMakeFiles/milestone3_4.dir/Server.cpp.o: CMakeFiles/milestone3_4.dir/flags.make
CMakeFiles/milestone3_4.dir/Server.cpp.o: ../Server.cpp
CMakeFiles/milestone3_4.dir/Server.cpp.o: CMakeFiles/milestone3_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/milestone3_4.dir/Server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/milestone3_4.dir/Server.cpp.o -MF CMakeFiles/milestone3_4.dir/Server.cpp.o.d -o CMakeFiles/milestone3_4.dir/Server.cpp.o -c /home/ori/CLionProjects/milestone3.4/Server.cpp

CMakeFiles/milestone3_4.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone3_4.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ori/CLionProjects/milestone3.4/Server.cpp > CMakeFiles/milestone3_4.dir/Server.cpp.i

CMakeFiles/milestone3_4.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone3_4.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ori/CLionProjects/milestone3.4/Server.cpp -o CMakeFiles/milestone3_4.dir/Server.cpp.s

CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.o: CMakeFiles/milestone3_4.dir/flags.make
CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.o: ../anomaly_detection_util.cpp
CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.o: CMakeFiles/milestone3_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.o -MF CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.o.d -o CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.o -c /home/ori/CLionProjects/milestone3.4/anomaly_detection_util.cpp

CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ori/CLionProjects/milestone3.4/anomaly_detection_util.cpp > CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.i

CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ori/CLionProjects/milestone3.4/anomaly_detection_util.cpp -o CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.s

CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.o: CMakeFiles/milestone3_4.dir/flags.make
CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.o: ../SimpleAnomalyDetector.cpp
CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.o: CMakeFiles/milestone3_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.o -MF CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.o.d -o CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.o -c /home/ori/CLionProjects/milestone3.4/SimpleAnomalyDetector.cpp

CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ori/CLionProjects/milestone3.4/SimpleAnomalyDetector.cpp > CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.i

CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ori/CLionProjects/milestone3.4/SimpleAnomalyDetector.cpp -o CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.s

CMakeFiles/milestone3_4.dir/timeseries.cpp.o: CMakeFiles/milestone3_4.dir/flags.make
CMakeFiles/milestone3_4.dir/timeseries.cpp.o: ../timeseries.cpp
CMakeFiles/milestone3_4.dir/timeseries.cpp.o: CMakeFiles/milestone3_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/milestone3_4.dir/timeseries.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/milestone3_4.dir/timeseries.cpp.o -MF CMakeFiles/milestone3_4.dir/timeseries.cpp.o.d -o CMakeFiles/milestone3_4.dir/timeseries.cpp.o -c /home/ori/CLionProjects/milestone3.4/timeseries.cpp

CMakeFiles/milestone3_4.dir/timeseries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone3_4.dir/timeseries.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ori/CLionProjects/milestone3.4/timeseries.cpp > CMakeFiles/milestone3_4.dir/timeseries.cpp.i

CMakeFiles/milestone3_4.dir/timeseries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone3_4.dir/timeseries.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ori/CLionProjects/milestone3.4/timeseries.cpp -o CMakeFiles/milestone3_4.dir/timeseries.cpp.s

CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.o: CMakeFiles/milestone3_4.dir/flags.make
CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.o: ../HybridAnomalyDetector.cpp
CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.o: CMakeFiles/milestone3_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.o -MF CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.o.d -o CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.o -c /home/ori/CLionProjects/milestone3.4/HybridAnomalyDetector.cpp

CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ori/CLionProjects/milestone3.4/HybridAnomalyDetector.cpp > CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.i

CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ori/CLionProjects/milestone3.4/HybridAnomalyDetector.cpp -o CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.s

CMakeFiles/milestone3_4.dir/minCircle.cpp.o: CMakeFiles/milestone3_4.dir/flags.make
CMakeFiles/milestone3_4.dir/minCircle.cpp.o: ../minCircle.cpp
CMakeFiles/milestone3_4.dir/minCircle.cpp.o: CMakeFiles/milestone3_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/milestone3_4.dir/minCircle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/milestone3_4.dir/minCircle.cpp.o -MF CMakeFiles/milestone3_4.dir/minCircle.cpp.o.d -o CMakeFiles/milestone3_4.dir/minCircle.cpp.o -c /home/ori/CLionProjects/milestone3.4/minCircle.cpp

CMakeFiles/milestone3_4.dir/minCircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone3_4.dir/minCircle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ori/CLionProjects/milestone3.4/minCircle.cpp > CMakeFiles/milestone3_4.dir/minCircle.cpp.i

CMakeFiles/milestone3_4.dir/minCircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone3_4.dir/minCircle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ori/CLionProjects/milestone3.4/minCircle.cpp -o CMakeFiles/milestone3_4.dir/minCircle.cpp.s

CMakeFiles/milestone3_4.dir/CLI.cpp.o: CMakeFiles/milestone3_4.dir/flags.make
CMakeFiles/milestone3_4.dir/CLI.cpp.o: ../CLI.cpp
CMakeFiles/milestone3_4.dir/CLI.cpp.o: CMakeFiles/milestone3_4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/milestone3_4.dir/CLI.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/milestone3_4.dir/CLI.cpp.o -MF CMakeFiles/milestone3_4.dir/CLI.cpp.o.d -o CMakeFiles/milestone3_4.dir/CLI.cpp.o -c /home/ori/CLionProjects/milestone3.4/CLI.cpp

CMakeFiles/milestone3_4.dir/CLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/milestone3_4.dir/CLI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ori/CLionProjects/milestone3.4/CLI.cpp > CMakeFiles/milestone3_4.dir/CLI.cpp.i

CMakeFiles/milestone3_4.dir/CLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/milestone3_4.dir/CLI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ori/CLionProjects/milestone3.4/CLI.cpp -o CMakeFiles/milestone3_4.dir/CLI.cpp.s

# Object files for target milestone3_4
milestone3_4_OBJECTS = \
"CMakeFiles/milestone3_4.dir/MainTrain.cpp.o" \
"CMakeFiles/milestone3_4.dir/Server.cpp.o" \
"CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.o" \
"CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.o" \
"CMakeFiles/milestone3_4.dir/timeseries.cpp.o" \
"CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.o" \
"CMakeFiles/milestone3_4.dir/minCircle.cpp.o" \
"CMakeFiles/milestone3_4.dir/CLI.cpp.o"

# External object files for target milestone3_4
milestone3_4_EXTERNAL_OBJECTS =

milestone3_4: CMakeFiles/milestone3_4.dir/MainTrain.cpp.o
milestone3_4: CMakeFiles/milestone3_4.dir/Server.cpp.o
milestone3_4: CMakeFiles/milestone3_4.dir/anomaly_detection_util.cpp.o
milestone3_4: CMakeFiles/milestone3_4.dir/SimpleAnomalyDetector.cpp.o
milestone3_4: CMakeFiles/milestone3_4.dir/timeseries.cpp.o
milestone3_4: CMakeFiles/milestone3_4.dir/HybridAnomalyDetector.cpp.o
milestone3_4: CMakeFiles/milestone3_4.dir/minCircle.cpp.o
milestone3_4: CMakeFiles/milestone3_4.dir/CLI.cpp.o
milestone3_4: CMakeFiles/milestone3_4.dir/build.make
milestone3_4: CMakeFiles/milestone3_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable milestone3_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/milestone3_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/milestone3_4.dir/build: milestone3_4
.PHONY : CMakeFiles/milestone3_4.dir/build

CMakeFiles/milestone3_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/milestone3_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/milestone3_4.dir/clean

CMakeFiles/milestone3_4.dir/depend:
	cd /home/ori/CLionProjects/milestone3.4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ori/CLionProjects/milestone3.4 /home/ori/CLionProjects/milestone3.4 /home/ori/CLionProjects/milestone3.4/cmake-build-debug /home/ori/CLionProjects/milestone3.4/cmake-build-debug /home/ori/CLionProjects/milestone3.4/cmake-build-debug/CMakeFiles/milestone3_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/milestone3_4.dir/depend

