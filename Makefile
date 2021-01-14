# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/harveybates/Documents/C++AnimationFramework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/harveybates/Documents/C++AnimationFramework

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.19.2/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.19.2/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/harveybates/Documents/C++AnimationFramework/CMakeFiles /Users/harveybates/Documents/C++AnimationFramework//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/harveybates/Documents/C++AnimationFramework/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named AnimationFramework

# Build rule for target.
AnimationFramework: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 AnimationFramework
.PHONY : AnimationFramework

# fast build rule for target.
AnimationFramework/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/build
.PHONY : AnimationFramework/fast

src/boids.o: src/boids.cpp.o

.PHONY : src/boids.o

# target to build an object file
src/boids.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/boids.cpp.o
.PHONY : src/boids.cpp.o

src/boids.i: src/boids.cpp.i

.PHONY : src/boids.i

# target to preprocess a source file
src/boids.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/boids.cpp.i
.PHONY : src/boids.cpp.i

src/boids.s: src/boids.cpp.s

.PHONY : src/boids.s

# target to generate assembly for a file
src/boids.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/boids.cpp.s
.PHONY : src/boids.cpp.s

src/graph.o: src/graph.cpp.o

.PHONY : src/graph.o

# target to build an object file
src/graph.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/graph.cpp.o
.PHONY : src/graph.cpp.o

src/graph.i: src/graph.cpp.i

.PHONY : src/graph.i

# target to preprocess a source file
src/graph.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/graph.cpp.i
.PHONY : src/graph.cpp.i

src/graph.s: src/graph.cpp.s

.PHONY : src/graph.s

# target to generate assembly for a file
src/graph.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/graph.cpp.s
.PHONY : src/graph.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/shapes.o: src/shapes.cpp.o

.PHONY : src/shapes.o

# target to build an object file
src/shapes.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/shapes.cpp.o
.PHONY : src/shapes.cpp.o

src/shapes.i: src/shapes.cpp.i

.PHONY : src/shapes.i

# target to preprocess a source file
src/shapes.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/shapes.cpp.i
.PHONY : src/shapes.cpp.i

src/shapes.s: src/shapes.cpp.s

.PHONY : src/shapes.s

# target to generate assembly for a file
src/shapes.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/shapes.cpp.s
.PHONY : src/shapes.cpp.s

src/transform.o: src/transform.cpp.o

.PHONY : src/transform.o

# target to build an object file
src/transform.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/transform.cpp.o
.PHONY : src/transform.cpp.o

src/transform.i: src/transform.cpp.i

.PHONY : src/transform.i

# target to preprocess a source file
src/transform.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/transform.cpp.i
.PHONY : src/transform.cpp.i

src/transform.s: src/transform.cpp.s

.PHONY : src/transform.s

# target to generate assembly for a file
src/transform.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/transform.cpp.s
.PHONY : src/transform.cpp.s

src/waves.o: src/waves.cpp.o

.PHONY : src/waves.o

# target to build an object file
src/waves.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/waves.cpp.o
.PHONY : src/waves.cpp.o

src/waves.i: src/waves.cpp.i

.PHONY : src/waves.i

# target to preprocess a source file
src/waves.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/waves.cpp.i
.PHONY : src/waves.cpp.i

src/waves.s: src/waves.cpp.s

.PHONY : src/waves.s

# target to generate assembly for a file
src/waves.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/AnimationFramework.dir/build.make CMakeFiles/AnimationFramework.dir/src/waves.cpp.s
.PHONY : src/waves.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... AnimationFramework"
	@echo "... src/boids.o"
	@echo "... src/boids.i"
	@echo "... src/boids.s"
	@echo "... src/graph.o"
	@echo "... src/graph.i"
	@echo "... src/graph.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/shapes.o"
	@echo "... src/shapes.i"
	@echo "... src/shapes.s"
	@echo "... src/transform.o"
	@echo "... src/transform.i"
	@echo "... src/transform.s"
	@echo "... src/waves.o"
	@echo "... src/waves.i"
	@echo "... src/waves.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

