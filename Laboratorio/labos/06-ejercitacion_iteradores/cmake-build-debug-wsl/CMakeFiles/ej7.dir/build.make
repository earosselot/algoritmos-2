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
CMAKE_SOURCE_DIR = /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/ej7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ej7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ej7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej7.dir/flags.make

CMakeFiles/ej7.dir/tests/algo_tests.cpp.o: CMakeFiles/ej7.dir/flags.make
CMakeFiles/ej7.dir/tests/algo_tests.cpp.o: ../tests/algo_tests.cpp
CMakeFiles/ej7.dir/tests/algo_tests.cpp.o: CMakeFiles/ej7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej7.dir/tests/algo_tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ej7.dir/tests/algo_tests.cpp.o -MF CMakeFiles/ej7.dir/tests/algo_tests.cpp.o.d -o CMakeFiles/ej7.dir/tests/algo_tests.cpp.o -c /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/tests/algo_tests.cpp

CMakeFiles/ej7.dir/tests/algo_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej7.dir/tests/algo_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/tests/algo_tests.cpp > CMakeFiles/ej7.dir/tests/algo_tests.cpp.i

CMakeFiles/ej7.dir/tests/algo_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej7.dir/tests/algo_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/tests/algo_tests.cpp -o CMakeFiles/ej7.dir/tests/algo_tests.cpp.s

# Object files for target ej7
ej7_OBJECTS = \
"CMakeFiles/ej7.dir/tests/algo_tests.cpp.o"

# External object files for target ej7
ej7_EXTERNAL_OBJECTS =

ej7: CMakeFiles/ej7.dir/tests/algo_tests.cpp.o
ej7: CMakeFiles/ej7.dir/build.make
ej7: libgtest.a
ej7: libgtest_main.a
ej7: CMakeFiles/ej7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej7.dir/build: ej7
.PHONY : CMakeFiles/ej7.dir/build

CMakeFiles/ej7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej7.dir/clean

CMakeFiles/ej7.dir/depend:
	cd /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/cmake-build-debug-wsl /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/cmake-build-debug-wsl /mnt/d/git/algoritmos-2/Laboratorio/labos/06-ejercitacion_iteradores/cmake-build-debug-wsl/CMakeFiles/ej7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej7.dir/depend

