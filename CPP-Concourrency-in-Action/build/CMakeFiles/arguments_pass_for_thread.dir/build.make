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
CMAKE_SOURCE_DIR = /home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/build

# Include any dependencies generated for this target.
include CMakeFiles/arguments_pass_for_thread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arguments_pass_for_thread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arguments_pass_for_thread.dir/flags.make

CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o: CMakeFiles/arguments_pass_for_thread.dir/flags.make
CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o: ../chapter2\ managing\ threads/arguments_pass_for_thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o -c "/home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/chapter2 managing threads/arguments_pass_for_thread.cpp"

CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/chapter2 managing threads/arguments_pass_for_thread.cpp" > CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.i

CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/chapter2 managing threads/arguments_pass_for_thread.cpp" -o CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.s

CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o.requires:

.PHONY : CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o.requires

CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o.provides: CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/arguments_pass_for_thread.dir/build.make CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o.provides.build
.PHONY : CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o.provides

CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o.provides.build: CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o


# Object files for target arguments_pass_for_thread
arguments_pass_for_thread_OBJECTS = \
"CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o"

# External object files for target arguments_pass_for_thread
arguments_pass_for_thread_EXTERNAL_OBJECTS =

devel/arguments_pass_for_thread: CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o
devel/arguments_pass_for_thread: CMakeFiles/arguments_pass_for_thread.dir/build.make
devel/arguments_pass_for_thread: CMakeFiles/arguments_pass_for_thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable devel/arguments_pass_for_thread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arguments_pass_for_thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arguments_pass_for_thread.dir/build: devel/arguments_pass_for_thread

.PHONY : CMakeFiles/arguments_pass_for_thread.dir/build

CMakeFiles/arguments_pass_for_thread.dir/requires: CMakeFiles/arguments_pass_for_thread.dir/chapter2_managing_threads/arguments_pass_for_thread.cpp.o.requires

.PHONY : CMakeFiles/arguments_pass_for_thread.dir/requires

CMakeFiles/arguments_pass_for_thread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arguments_pass_for_thread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arguments_pass_for_thread.dir/clean

CMakeFiles/arguments_pass_for_thread.dir/depend:
	cd /home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action /home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action /home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/build /home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/build /home/lwl/workspace/CPlusPlusPratice/CPP-Concourrency-in-Action/build/CMakeFiles/arguments_pass_for_thread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arguments_pass_for_thread.dir/depend
