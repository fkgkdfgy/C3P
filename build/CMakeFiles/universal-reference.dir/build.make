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
include CMakeFiles/universal-reference.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/universal-reference.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/universal-reference.dir/flags.make

CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o: CMakeFiles/universal-reference.dir/flags.make
CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o: ../CPP11/reference/universal-reference.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lwl/workspace/CPlusPlusPratice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o"
	/usr/bin/g++-5   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o -c /home/lwl/workspace/CPlusPlusPratice/CPP11/reference/universal-reference.cpp

CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.i"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lwl/workspace/CPlusPlusPratice/CPP11/reference/universal-reference.cpp > CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.i

CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.s"
	/usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lwl/workspace/CPlusPlusPratice/CPP11/reference/universal-reference.cpp -o CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.s

CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o.requires:

.PHONY : CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o.requires

CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o.provides: CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o.requires
	$(MAKE) -f CMakeFiles/universal-reference.dir/build.make CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o.provides.build
.PHONY : CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o.provides

CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o.provides.build: CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o


# Object files for target universal-reference
universal__reference_OBJECTS = \
"CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o"

# External object files for target universal-reference
universal__reference_EXTERNAL_OBJECTS =

executable/universal-reference: CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o
executable/universal-reference: CMakeFiles/universal-reference.dir/build.make
executable/universal-reference: CMakeFiles/universal-reference.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lwl/workspace/CPlusPlusPratice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable executable/universal-reference"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/universal-reference.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/universal-reference.dir/build: executable/universal-reference

.PHONY : CMakeFiles/universal-reference.dir/build

CMakeFiles/universal-reference.dir/requires: CMakeFiles/universal-reference.dir/CPP11/reference/universal-reference.cpp.o.requires

.PHONY : CMakeFiles/universal-reference.dir/requires

CMakeFiles/universal-reference.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/universal-reference.dir/cmake_clean.cmake
.PHONY : CMakeFiles/universal-reference.dir/clean

CMakeFiles/universal-reference.dir/depend:
	cd /home/lwl/workspace/CPlusPlusPratice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lwl/workspace/CPlusPlusPratice /home/lwl/workspace/CPlusPlusPratice /home/lwl/workspace/CPlusPlusPratice/build /home/lwl/workspace/CPlusPlusPratice/build /home/lwl/workspace/CPlusPlusPratice/build/CMakeFiles/universal-reference.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/universal-reference.dir/depend

