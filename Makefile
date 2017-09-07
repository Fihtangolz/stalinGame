# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dns/Documents/CDL+CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dns/Documents/CDL+CPP

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.9.1/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.9.1/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/dns/Documents/CDL+CPP/CMakeFiles /Users/dns/Documents/CDL+CPP/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/dns/Documents/CDL+CPP/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named SimpleGame

# Build rule for target.
SimpleGame: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SimpleGame
.PHONY : SimpleGame

# fast build rule for target.
SimpleGame/fast:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/build
.PHONY : SimpleGame/fast

src/gameField.o: src/gameField.cpp.o

.PHONY : src/gameField.o

# target to build an object file
src/gameField.cpp.o:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/gameField.cpp.o
.PHONY : src/gameField.cpp.o

src/gameField.i: src/gameField.cpp.i

.PHONY : src/gameField.i

# target to preprocess a source file
src/gameField.cpp.i:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/gameField.cpp.i
.PHONY : src/gameField.cpp.i

src/gameField.s: src/gameField.cpp.s

.PHONY : src/gameField.s

# target to generate assembly for a file
src/gameField.cpp.s:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/gameField.cpp.s
.PHONY : src/gameField.cpp.s

src/keyboardHandler.o: src/keyboardHandler.cpp.o

.PHONY : src/keyboardHandler.o

# target to build an object file
src/keyboardHandler.cpp.o:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/keyboardHandler.cpp.o
.PHONY : src/keyboardHandler.cpp.o

src/keyboardHandler.i: src/keyboardHandler.cpp.i

.PHONY : src/keyboardHandler.i

# target to preprocess a source file
src/keyboardHandler.cpp.i:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/keyboardHandler.cpp.i
.PHONY : src/keyboardHandler.cpp.i

src/keyboardHandler.s: src/keyboardHandler.cpp.s

.PHONY : src/keyboardHandler.s

# target to generate assembly for a file
src/keyboardHandler.cpp.s:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/keyboardHandler.cpp.s
.PHONY : src/keyboardHandler.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/resourceManager.o: src/resourceManager.cpp.o

.PHONY : src/resourceManager.o

# target to build an object file
src/resourceManager.cpp.o:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/resourceManager.cpp.o
.PHONY : src/resourceManager.cpp.o

src/resourceManager.i: src/resourceManager.cpp.i

.PHONY : src/resourceManager.i

# target to preprocess a source file
src/resourceManager.cpp.i:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/resourceManager.cpp.i
.PHONY : src/resourceManager.cpp.i

src/resourceManager.s: src/resourceManager.cpp.s

.PHONY : src/resourceManager.s

# target to generate assembly for a file
src/resourceManager.cpp.s:
	$(MAKE) -f CMakeFiles/SimpleGame.dir/build.make CMakeFiles/SimpleGame.dir/src/resourceManager.cpp.s
.PHONY : src/resourceManager.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... SimpleGame"
	@echo "... src/gameField.o"
	@echo "... src/gameField.i"
	@echo "... src/gameField.s"
	@echo "... src/keyboardHandler.o"
	@echo "... src/keyboardHandler.i"
	@echo "... src/keyboardHandler.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/resourceManager.o"
	@echo "... src/resourceManager.i"
	@echo "... src/resourceManager.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

