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
include CMakeFiles/include-main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/include-main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/include-main.dir/flags.make

CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o: CMakeFiles/include-main.dir/flags.make
CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o: ../BasicContent/include-error/include-main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lwl/workspace/CPlusPlusPratice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o -c /home/lwl/workspace/CPlusPlusPratice/BasicContent/include-error/include-main.cpp

CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lwl/workspace/CPlusPlusPratice/BasicContent/include-error/include-main.cpp > CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.i

CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lwl/workspace/CPlusPlusPratice/BasicContent/include-error/include-main.cpp -o CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.s

CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o.requires:

.PHONY : CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o.requires

CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o.provides: CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o.requires
	$(MAKE) -f CMakeFiles/include-main.dir/build.make CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o.provides.build
.PHONY : CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o.provides

CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o.provides.build: CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o


# Object files for target include-main
include__main_OBJECTS = \
"CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o"

# External object files for target include-main
include__main_EXTERNAL_OBJECTS =

executable/include-main: CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o
executable/include-main: CMakeFiles/include-main.dir/build.make
executable/include-main: CMakeFiles/include-main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lwl/workspace/CPlusPlusPratice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable executable/include-main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/include-main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/include-main.dir/build: executable/include-main

.PHONY : CMakeFiles/include-main.dir/build

CMakeFiles/include-main.dir/requires: CMakeFiles/include-main.dir/BasicContent/include-error/include-main.cpp.o.requires

.PHONY : CMakeFiles/include-main.dir/requires

CMakeFiles/include-main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/include-main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/include-main.dir/clean

CMakeFiles/include-main.dir/depend:
	cd /home/lwl/workspace/CPlusPlusPratice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lwl/workspace/CPlusPlusPratice /home/lwl/workspace/CPlusPlusPratice /home/lwl/workspace/CPlusPlusPratice/build /home/lwl/workspace/CPlusPlusPratice/build /home/lwl/workspace/CPlusPlusPratice/build/CMakeFiles/include-main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/include-main.dir/depend

