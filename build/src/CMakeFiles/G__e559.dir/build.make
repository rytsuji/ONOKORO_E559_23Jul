# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/tsuji/work/art_analysis/e559_23jul

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tsuji/work/art_analysis/e559_23jul/build

# Include any dependencies generated for this target.
include src/CMakeFiles/G__e559.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/G__e559.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/G__e559.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/G__e559.dir/flags.make

src/G__e559.cxx: ../src/linkdef_user.h
src/G__e559.cxx: ../src/TVDCClusterizationProcessor_mod.h
src/G__e559.cxx: ../src/TVDCTrackingProcessor_mod.h
src/G__e559.cxx: ../src/TTimingChargeMultiHitMappingProcessor.h
src/G__e559.cxx: ../src/TVDCClusterizationProcessor_mod.h
src/G__e559.cxx: ../src/TVDCTrackingProcessor_mod.h
src/G__e559.cxx: ../src/TTimingChargeMultiHitMappingProcessor.h
src/G__e559.cxx: ../src/linkdef_user.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/tsuji/work/art_analysis/e559_23jul/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating G__e559.cxx, libe559_rdict.pcm, libe559.rootmap"
	cd /home/tsuji/work/art_analysis/e559_23jul/build/src && /usr/bin/cmake -E env LD_LIBRARY_PATH=/home/quser/local/root/v6.26.10/lib:/home/quser/local/artemis/artemis-e559/lib::/home/quser/local/root/v6.26.10/lib:/home/quser/local/yaml-cpp/yaml-cpp-0.6.3/lib: /home/quser/local/root/v6.26.10/bin/rootcling -v2 -f G__e559.cxx -s /home/tsuji/work/art_analysis/e559_23jul/build/src/libe559.so -rml libe559.so -rmf /home/tsuji/work/art_analysis/e559_23jul/build/src/libe559.rootmap -compilerI/usr/include/c++/8 -compilerI/usr/include/c++/8/x86_64-redhat-linux -compilerI/usr/include/c++/8/backward -compilerI/usr/lib/gcc/x86_64-redhat-linux/8/include -compilerI/usr/local/include -compilerI/usr/include -compilerI/usr/lib/gcc/x86_64-redhat-linux/8/include -compilerI/usr/local/include -compilerI/usr/include -I/home/quser/local/root/v6.26.10/include -I/home/tsuji/work/art_analysis/e559_23jul/src -I/home/quser/local/root/v6.26.10/include -I/home/tsuji/work/art_analysis/e559_23jul/src -I/home/quser/local/artemis/artemis-e559/include/. -I/home/quser/local/artemis/artemis-e559/include -I/home/quser/local/yaml-cpp/yaml-cpp-0.6.3/include TVDCClusterizationProcessor_mod.h TVDCTrackingProcessor_mod.h TTimingChargeMultiHitMappingProcessor.h /home/tsuji/work/art_analysis/e559_23jul/src/linkdef_user.h

src/libe559_rdict.pcm: src/G__e559.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate src/libe559_rdict.pcm

src/libe559.rootmap: src/G__e559.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate src/libe559.rootmap

src/CMakeFiles/G__e559.dir/G__e559.cxx.o: src/CMakeFiles/G__e559.dir/flags.make
src/CMakeFiles/G__e559.dir/G__e559.cxx.o: src/G__e559.cxx
src/CMakeFiles/G__e559.dir/G__e559.cxx.o: src/CMakeFiles/G__e559.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tsuji/work/art_analysis/e559_23jul/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/G__e559.dir/G__e559.cxx.o"
	cd /home/tsuji/work/art_analysis/e559_23jul/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/G__e559.dir/G__e559.cxx.o -MF CMakeFiles/G__e559.dir/G__e559.cxx.o.d -o CMakeFiles/G__e559.dir/G__e559.cxx.o -c /home/tsuji/work/art_analysis/e559_23jul/build/src/G__e559.cxx

src/CMakeFiles/G__e559.dir/G__e559.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/G__e559.dir/G__e559.cxx.i"
	cd /home/tsuji/work/art_analysis/e559_23jul/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tsuji/work/art_analysis/e559_23jul/build/src/G__e559.cxx > CMakeFiles/G__e559.dir/G__e559.cxx.i

src/CMakeFiles/G__e559.dir/G__e559.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/G__e559.dir/G__e559.cxx.s"
	cd /home/tsuji/work/art_analysis/e559_23jul/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tsuji/work/art_analysis/e559_23jul/build/src/G__e559.cxx -o CMakeFiles/G__e559.dir/G__e559.cxx.s

G__e559: src/CMakeFiles/G__e559.dir/G__e559.cxx.o
G__e559: src/CMakeFiles/G__e559.dir/build.make
.PHONY : G__e559

# Rule to build all files generated by this target.
src/CMakeFiles/G__e559.dir/build: G__e559
.PHONY : src/CMakeFiles/G__e559.dir/build

src/CMakeFiles/G__e559.dir/clean:
	cd /home/tsuji/work/art_analysis/e559_23jul/build/src && $(CMAKE_COMMAND) -P CMakeFiles/G__e559.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/G__e559.dir/clean

src/CMakeFiles/G__e559.dir/depend: src/G__e559.cxx
src/CMakeFiles/G__e559.dir/depend: src/libe559.rootmap
src/CMakeFiles/G__e559.dir/depend: src/libe559_rdict.pcm
	cd /home/tsuji/work/art_analysis/e559_23jul/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tsuji/work/art_analysis/e559_23jul /home/tsuji/work/art_analysis/e559_23jul/src /home/tsuji/work/art_analysis/e559_23jul/build /home/tsuji/work/art_analysis/e559_23jul/build/src /home/tsuji/work/art_analysis/e559_23jul/build/src/CMakeFiles/G__e559.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/G__e559.dir/depend
