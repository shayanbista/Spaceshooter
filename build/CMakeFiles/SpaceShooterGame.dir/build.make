# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/leapfrog/Documents/spaceshootergame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leapfrog/Documents/spaceshootergame/build

# Include any dependencies generated for this target.
include CMakeFiles/SpaceShooterGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SpaceShooterGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SpaceShooterGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SpaceShooterGame.dir/flags.make

CMakeFiles/SpaceShooterGame.dir/main.cpp.o: CMakeFiles/SpaceShooterGame.dir/flags.make
CMakeFiles/SpaceShooterGame.dir/main.cpp.o: ../main.cpp
CMakeFiles/SpaceShooterGame.dir/main.cpp.o: CMakeFiles/SpaceShooterGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leapfrog/Documents/spaceshootergame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SpaceShooterGame.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SpaceShooterGame.dir/main.cpp.o -MF CMakeFiles/SpaceShooterGame.dir/main.cpp.o.d -o CMakeFiles/SpaceShooterGame.dir/main.cpp.o -c /home/leapfrog/Documents/spaceshootergame/main.cpp

CMakeFiles/SpaceShooterGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpaceShooterGame.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leapfrog/Documents/spaceshootergame/main.cpp > CMakeFiles/SpaceShooterGame.dir/main.cpp.i

CMakeFiles/SpaceShooterGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpaceShooterGame.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leapfrog/Documents/spaceshootergame/main.cpp -o CMakeFiles/SpaceShooterGame.dir/main.cpp.s

CMakeFiles/SpaceShooterGame.dir/map.cpp.o: CMakeFiles/SpaceShooterGame.dir/flags.make
CMakeFiles/SpaceShooterGame.dir/map.cpp.o: ../map.cpp
CMakeFiles/SpaceShooterGame.dir/map.cpp.o: CMakeFiles/SpaceShooterGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leapfrog/Documents/spaceshootergame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SpaceShooterGame.dir/map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SpaceShooterGame.dir/map.cpp.o -MF CMakeFiles/SpaceShooterGame.dir/map.cpp.o.d -o CMakeFiles/SpaceShooterGame.dir/map.cpp.o -c /home/leapfrog/Documents/spaceshootergame/map.cpp

CMakeFiles/SpaceShooterGame.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SpaceShooterGame.dir/map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leapfrog/Documents/spaceshootergame/map.cpp > CMakeFiles/SpaceShooterGame.dir/map.cpp.i

CMakeFiles/SpaceShooterGame.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SpaceShooterGame.dir/map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leapfrog/Documents/spaceshootergame/map.cpp -o CMakeFiles/SpaceShooterGame.dir/map.cpp.s

# Object files for target SpaceShooterGame
SpaceShooterGame_OBJECTS = \
"CMakeFiles/SpaceShooterGame.dir/main.cpp.o" \
"CMakeFiles/SpaceShooterGame.dir/map.cpp.o"

# External object files for target SpaceShooterGame
SpaceShooterGame_EXTERNAL_OBJECTS =

SpaceShooterGame: CMakeFiles/SpaceShooterGame.dir/main.cpp.o
SpaceShooterGame: CMakeFiles/SpaceShooterGame.dir/map.cpp.o
SpaceShooterGame: CMakeFiles/SpaceShooterGame.dir/build.make
SpaceShooterGame: CMakeFiles/SpaceShooterGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leapfrog/Documents/spaceshootergame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SpaceShooterGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpaceShooterGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SpaceShooterGame.dir/build: SpaceShooterGame
.PHONY : CMakeFiles/SpaceShooterGame.dir/build

CMakeFiles/SpaceShooterGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SpaceShooterGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SpaceShooterGame.dir/clean

CMakeFiles/SpaceShooterGame.dir/depend:
	cd /home/leapfrog/Documents/spaceshootergame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leapfrog/Documents/spaceshootergame /home/leapfrog/Documents/spaceshootergame /home/leapfrog/Documents/spaceshootergame/build /home/leapfrog/Documents/spaceshootergame/build /home/leapfrog/Documents/spaceshootergame/build/CMakeFiles/SpaceShooterGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SpaceShooterGame.dir/depend

