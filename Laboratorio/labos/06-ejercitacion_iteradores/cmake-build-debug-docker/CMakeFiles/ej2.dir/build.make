# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/06-ejercitacion_iteradores

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/06-ejercitacion_iteradores/cmake-build-debug-docker

# Include any dependencies generated for this target.
include CMakeFiles/ej2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ej2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ej2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej2.dir/flags.make

CMakeFiles/ej2.dir/tests/algo_tests.cpp.o: CMakeFiles/ej2.dir/flags.make
CMakeFiles/ej2.dir/tests/algo_tests.cpp.o: ../tests/algo_tests.cpp
CMakeFiles/ej2.dir/tests/algo_tests.cpp.o: CMakeFiles/ej2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/06-ejercitacion_iteradores/cmake-build-debug-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej2.dir/tests/algo_tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ej2.dir/tests/algo_tests.cpp.o -MF CMakeFiles/ej2.dir/tests/algo_tests.cpp.o.d -o CMakeFiles/ej2.dir/tests/algo_tests.cpp.o -c /tmp/06-ejercitacion_iteradores/tests/algo_tests.cpp

CMakeFiles/ej2.dir/tests/algo_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej2.dir/tests/algo_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/06-ejercitacion_iteradores/tests/algo_tests.cpp > CMakeFiles/ej2.dir/tests/algo_tests.cpp.i

CMakeFiles/ej2.dir/tests/algo_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej2.dir/tests/algo_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/06-ejercitacion_iteradores/tests/algo_tests.cpp -o CMakeFiles/ej2.dir/tests/algo_tests.cpp.s

# Object files for target ej2
ej2_OBJECTS = \
"CMakeFiles/ej2.dir/tests/algo_tests.cpp.o"

# External object files for target ej2
ej2_EXTERNAL_OBJECTS =

ej2: CMakeFiles/ej2.dir/tests/algo_tests.cpp.o
ej2: CMakeFiles/ej2.dir/build.make
ej2: libgtest.a
ej2: libgtest_main.a
ej2: CMakeFiles/ej2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/06-ejercitacion_iteradores/cmake-build-debug-docker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej2.dir/build: ej2
.PHONY : CMakeFiles/ej2.dir/build

CMakeFiles/ej2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej2.dir/clean

CMakeFiles/ej2.dir/depend:
	cd /tmp/06-ejercitacion_iteradores/cmake-build-debug-docker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/06-ejercitacion_iteradores /tmp/06-ejercitacion_iteradores /tmp/06-ejercitacion_iteradores/cmake-build-debug-docker /tmp/06-ejercitacion_iteradores/cmake-build-debug-docker /tmp/06-ejercitacion_iteradores/cmake-build-debug-docker/CMakeFiles/ej2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej2.dir/depend

