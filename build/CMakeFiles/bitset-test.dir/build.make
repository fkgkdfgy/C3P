# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/sunny/workspace_private/C3P

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunny/workspace_private/C3P/build

# Include any dependencies generated for this target.
include CMakeFiles/bitset-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bitset-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bitset-test.dir/flags.make

CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o: CMakeFiles/bitset-test.dir/flags.make
CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o: ../Carto-self-test/bitset/bitset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunny/workspace_private/C3P/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o -c /home/sunny/workspace_private/C3P/Carto-self-test/bitset/bitset.cpp

CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunny/workspace_private/C3P/Carto-self-test/bitset/bitset.cpp > CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.i

CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunny/workspace_private/C3P/Carto-self-test/bitset/bitset.cpp -o CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.s

CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o.requires:

.PHONY : CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o.requires

CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o.provides: CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o.requires
	$(MAKE) -f CMakeFiles/bitset-test.dir/build.make CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o.provides.build
.PHONY : CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o.provides

CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o.provides.build: CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o


# Object files for target bitset-test
bitset__test_OBJECTS = \
"CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o"

# External object files for target bitset-test
bitset__test_EXTERNAL_OBJECTS =

executable/bitset-test: CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o
executable/bitset-test: CMakeFiles/bitset-test.dir/build.make
executable/bitset-test: CMakeFiles/bitset-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunny/workspace_private/C3P/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable executable/bitset-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bitset-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bitset-test.dir/build: executable/bitset-test

.PHONY : CMakeFiles/bitset-test.dir/build

CMakeFiles/bitset-test.dir/requires: CMakeFiles/bitset-test.dir/Carto-self-test/bitset/bitset.cpp.o.requires

.PHONY : CMakeFiles/bitset-test.dir/requires

CMakeFiles/bitset-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bitset-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bitset-test.dir/clean

CMakeFiles/bitset-test.dir/depend:
	cd /home/sunny/workspace_private/C3P/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunny/workspace_private/C3P /home/sunny/workspace_private/C3P /home/sunny/workspace_private/C3P/build /home/sunny/workspace_private/C3P/build /home/sunny/workspace_private/C3P/build/CMakeFiles/bitset-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bitset-test.dir/depend

