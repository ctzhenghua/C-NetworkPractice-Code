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
CMAKE_SOURCE_DIR = /home/hua/C-NetworkPractice-Code/Tools/CMake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hua/C-NetworkPractice-Code/Tools/CMake

# Include any dependencies generated for this target.
include src/CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Test.dir/flags.make

src/CMakeFiles/Test.dir/Test.cc.o: src/CMakeFiles/Test.dir/flags.make
src/CMakeFiles/Test.dir/Test.cc.o: src/Test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hua/C-NetworkPractice-Code/Tools/CMake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Test.dir/Test.cc.o"
	cd /home/hua/C-NetworkPractice-Code/Tools/CMake/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/Test.cc.o -c /home/hua/C-NetworkPractice-Code/Tools/CMake/src/Test.cc

src/CMakeFiles/Test.dir/Test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/Test.cc.i"
	cd /home/hua/C-NetworkPractice-Code/Tools/CMake/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hua/C-NetworkPractice-Code/Tools/CMake/src/Test.cc > CMakeFiles/Test.dir/Test.cc.i

src/CMakeFiles/Test.dir/Test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/Test.cc.s"
	cd /home/hua/C-NetworkPractice-Code/Tools/CMake/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hua/C-NetworkPractice-Code/Tools/CMake/src/Test.cc -o CMakeFiles/Test.dir/Test.cc.s

src/CMakeFiles/Test.dir/Test.cc.o.requires:

.PHONY : src/CMakeFiles/Test.dir/Test.cc.o.requires

src/CMakeFiles/Test.dir/Test.cc.o.provides: src/CMakeFiles/Test.dir/Test.cc.o.requires
	$(MAKE) -f src/CMakeFiles/Test.dir/build.make src/CMakeFiles/Test.dir/Test.cc.o.provides.build
.PHONY : src/CMakeFiles/Test.dir/Test.cc.o.provides

src/CMakeFiles/Test.dir/Test.cc.o.provides.build: src/CMakeFiles/Test.dir/Test.cc.o


# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/Test.cc.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

src/libTest.a: src/CMakeFiles/Test.dir/Test.cc.o
src/libTest.a: src/CMakeFiles/Test.dir/build.make
src/libTest.a: src/CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hua/C-NetworkPractice-Code/Tools/CMake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTest.a"
	cd /home/hua/C-NetworkPractice-Code/Tools/CMake/src && $(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean_target.cmake
	cd /home/hua/C-NetworkPractice-Code/Tools/CMake/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Test.dir/build: src/libTest.a

.PHONY : src/CMakeFiles/Test.dir/build

src/CMakeFiles/Test.dir/requires: src/CMakeFiles/Test.dir/Test.cc.o.requires

.PHONY : src/CMakeFiles/Test.dir/requires

src/CMakeFiles/Test.dir/clean:
	cd /home/hua/C-NetworkPractice-Code/Tools/CMake/src && $(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Test.dir/clean

src/CMakeFiles/Test.dir/depend:
	cd /home/hua/C-NetworkPractice-Code/Tools/CMake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hua/C-NetworkPractice-Code/Tools/CMake /home/hua/C-NetworkPractice-Code/Tools/CMake/src /home/hua/C-NetworkPractice-Code/Tools/CMake /home/hua/C-NetworkPractice-Code/Tools/CMake/src /home/hua/C-NetworkPractice-Code/Tools/CMake/src/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Test.dir/depend

