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
CMAKE_SOURCE_DIR = /home/lwl/workspace/CPlusPlusPratice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lwl/workspace/CPlusPlusPratice/build

# Include any dependencies generated for this target.
include CMakeFiles/functor-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/functor-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/functor-test.dir/flags.make

CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o: CMakeFiles/functor-test.dir/flags.make
CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o: ../BasicContent/functor/functor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lwl/workspace/CPlusPlusPratice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o -c /home/lwl/workspace/CPlusPlusPratice/BasicContent/functor/functor.cpp

CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lwl/workspace/CPlusPlusPratice/BasicContent/functor/functor.cpp > CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.i

CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lwl/workspace/CPlusPlusPratice/BasicContent/functor/functor.cpp -o CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.s

CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o.requires:

.PHONY : CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o.requires

CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o.provides: CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o.requires
	$(MAKE) -f CMakeFiles/functor-test.dir/build.make CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o.provides.build
.PHONY : CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o.provides

CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o.provides.build: CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o


# Object files for target functor-test
functor__test_OBJECTS = \
"CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o"

# External object files for target functor-test
functor__test_EXTERNAL_OBJECTS =

executable/functor-test: CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o
executable/functor-test: CMakeFiles/functor-test.dir/build.make
executable/functor-test: CMakeFiles/functor-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lwl/workspace/CPlusPlusPratice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable executable/functor-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/functor-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/functor-test.dir/build: executable/functor-test

.PHONY : CMakeFiles/functor-test.dir/build

CMakeFiles/functor-test.dir/requires: CMakeFiles/functor-test.dir/BasicContent/functor/functor.cpp.o.requires

.PHONY : CMakeFiles/functor-test.dir/requires

CMakeFiles/functor-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/functor-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/functor-test.dir/clean

CMakeFiles/functor-test.dir/depend:
	cd /home/lwl/workspace/CPlusPlusPratice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lwl/workspace/CPlusPlusPratice /home/lwl/workspace/CPlusPlusPratice /home/lwl/workspace/CPlusPlusPratice/build /home/lwl/workspace/CPlusPlusPratice/build /home/lwl/workspace/CPlusPlusPratice/build/CMakeFiles/functor-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/functor-test.dir/depend

