# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/gokatsuki/workspace/tc_ws/Brainfuck

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gokatsuki/workspace/tc_ws/Brainfuck/build

# Include any dependencies generated for this target.
include CMakeFiles/bf_compiler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bf_compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bf_compiler.dir/flags.make

CMakeFiles/bf_compiler.dir/bf_compiler.cpp.o: CMakeFiles/bf_compiler.dir/flags.make
CMakeFiles/bf_compiler.dir/bf_compiler.cpp.o: ../bf_compiler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gokatsuki/workspace/tc_ws/Brainfuck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bf_compiler.dir/bf_compiler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bf_compiler.dir/bf_compiler.cpp.o -c /home/gokatsuki/workspace/tc_ws/Brainfuck/bf_compiler.cpp

CMakeFiles/bf_compiler.dir/bf_compiler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bf_compiler.dir/bf_compiler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gokatsuki/workspace/tc_ws/Brainfuck/bf_compiler.cpp > CMakeFiles/bf_compiler.dir/bf_compiler.cpp.i

CMakeFiles/bf_compiler.dir/bf_compiler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bf_compiler.dir/bf_compiler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gokatsuki/workspace/tc_ws/Brainfuck/bf_compiler.cpp -o CMakeFiles/bf_compiler.dir/bf_compiler.cpp.s

# Object files for target bf_compiler
bf_compiler_OBJECTS = \
"CMakeFiles/bf_compiler.dir/bf_compiler.cpp.o"

# External object files for target bf_compiler
bf_compiler_EXTERNAL_OBJECTS =

bf_compiler: CMakeFiles/bf_compiler.dir/bf_compiler.cpp.o
bf_compiler: CMakeFiles/bf_compiler.dir/build.make
bf_compiler: CMakeFiles/bf_compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gokatsuki/workspace/tc_ws/Brainfuck/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bf_compiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bf_compiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bf_compiler.dir/build: bf_compiler

.PHONY : CMakeFiles/bf_compiler.dir/build

CMakeFiles/bf_compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bf_compiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bf_compiler.dir/clean

CMakeFiles/bf_compiler.dir/depend:
	cd /home/gokatsuki/workspace/tc_ws/Brainfuck/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gokatsuki/workspace/tc_ws/Brainfuck /home/gokatsuki/workspace/tc_ws/Brainfuck /home/gokatsuki/workspace/tc_ws/Brainfuck/build /home/gokatsuki/workspace/tc_ws/Brainfuck/build /home/gokatsuki/workspace/tc_ws/Brainfuck/build/CMakeFiles/bf_compiler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bf_compiler.dir/depend
