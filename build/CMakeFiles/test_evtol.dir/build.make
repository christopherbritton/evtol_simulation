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
CMAKE_SOURCE_DIR = /workspaces/evtol_simulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/evtol_simulation/build

# Include any dependencies generated for this target.
include CMakeFiles/test_evtol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_evtol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_evtol.dir/flags.make

CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.o: CMakeFiles/test_evtol.dir/flags.make
CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.o: ../tests/test_evtol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/evtol_simulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.o -c /workspaces/evtol_simulation/tests/test_evtol.cpp

CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/evtol_simulation/tests/test_evtol.cpp > CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.i

CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/evtol_simulation/tests/test_evtol.cpp -o CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.s

# Object files for target test_evtol
test_evtol_OBJECTS = \
"CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.o"

# External object files for target test_evtol
test_evtol_EXTERNAL_OBJECTS =

test_evtol: CMakeFiles/test_evtol.dir/tests/test_evtol.cpp.o
test_evtol: CMakeFiles/test_evtol.dir/build.make
test_evtol: libcore_sources.a
test_evtol: CMakeFiles/test_evtol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/evtol_simulation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_evtol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_evtol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_evtol.dir/build: test_evtol

.PHONY : CMakeFiles/test_evtol.dir/build

CMakeFiles/test_evtol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_evtol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_evtol.dir/clean

CMakeFiles/test_evtol.dir/depend:
	cd /workspaces/evtol_simulation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/evtol_simulation /workspaces/evtol_simulation /workspaces/evtol_simulation/build /workspaces/evtol_simulation/build /workspaces/evtol_simulation/build/CMakeFiles/test_evtol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_evtol.dir/depend

