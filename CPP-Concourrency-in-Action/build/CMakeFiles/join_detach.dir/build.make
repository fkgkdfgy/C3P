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
CMAKE_SOURCE_DIR = /home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/build

# Include any dependencies generated for this target.
include CMakeFiles/join_detach.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/join_detach.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/join_detach.dir/flags.make

CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o: CMakeFiles/join_detach.dir/flags.make
CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o: ../chapter2\ managing\ threads/join_detach.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o -c "/home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/chapter2 managing threads/join_detach.cpp"

CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/chapter2 managing threads/join_detach.cpp" > CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.i

CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/chapter2 managing threads/join_detach.cpp" -o CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.s

CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o.requires:

.PHONY : CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o.requires

CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o.provides: CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o.requires
	$(MAKE) -f CMakeFiles/join_detach.dir/build.make CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o.provides.build
.PHONY : CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o.provides

CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o.provides.build: CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o


# Object files for target join_detach
join_detach_OBJECTS = \
"CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o"

# External object files for target join_detach
join_detach_EXTERNAL_OBJECTS =

devel/join_detach: CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o
devel/join_detach: CMakeFiles/join_detach.dir/build.make
devel/join_detach: CMakeFiles/join_detach.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable devel/join_detach"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/join_detach.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/join_detach.dir/build: devel/join_detach

.PHONY : CMakeFiles/join_detach.dir/build

CMakeFiles/join_detach.dir/requires: CMakeFiles/join_detach.dir/chapter2_managing_threads/join_detach.cpp.o.requires

.PHONY : CMakeFiles/join_detach.dir/requires

CMakeFiles/join_detach.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/join_detach.dir/cmake_clean.cmake
.PHONY : CMakeFiles/join_detach.dir/clean

CMakeFiles/join_detach.dir/depend:
	cd /home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action /home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action /home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/build /home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/build /home/sunny/workspace_private/C3P/CPP-Concourrency-in-Action/build/CMakeFiles/join_detach.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/join_detach.dir/depend

