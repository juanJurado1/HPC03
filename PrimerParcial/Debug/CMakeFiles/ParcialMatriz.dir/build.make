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
CMAKE_SOURCE_DIR = /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/Debug

# Include any dependencies generated for this target.
include CMakeFiles/ParcialMatriz.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ParcialMatriz.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ParcialMatriz.dir/flags.make

CMakeFiles/ParcialMatriz.dir/main.cpp.o: CMakeFiles/ParcialMatriz.dir/flags.make
CMakeFiles/ParcialMatriz.dir/main.cpp.o: /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ParcialMatriz.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParcialMatriz.dir/main.cpp.o -c /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz/main.cpp

CMakeFiles/ParcialMatriz.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParcialMatriz.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz/main.cpp > CMakeFiles/ParcialMatriz.dir/main.cpp.i

CMakeFiles/ParcialMatriz.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParcialMatriz.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz/main.cpp -o CMakeFiles/ParcialMatriz.dir/main.cpp.s

CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.o: CMakeFiles/ParcialMatriz.dir/flags.make
CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.o: /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz/FMATRIZ/funciones.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.o -c /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz/FMATRIZ/funciones.cpp

CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz/FMATRIZ/funciones.cpp > CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.i

CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz/FMATRIZ/funciones.cpp -o CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.s

# Object files for target ParcialMatriz
ParcialMatriz_OBJECTS = \
"CMakeFiles/ParcialMatriz.dir/main.cpp.o" \
"CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.o"

# External object files for target ParcialMatriz
ParcialMatriz_EXTERNAL_OBJECTS =

ParcialMatriz: CMakeFiles/ParcialMatriz.dir/main.cpp.o
ParcialMatriz: CMakeFiles/ParcialMatriz.dir/FMATRIZ/funciones.cpp.o
ParcialMatriz: CMakeFiles/ParcialMatriz.dir/build.make
ParcialMatriz: CMakeFiles/ParcialMatriz.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ParcialMatriz"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ParcialMatriz.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ParcialMatriz.dir/build: ParcialMatriz

.PHONY : CMakeFiles/ParcialMatriz.dir/build

CMakeFiles/ParcialMatriz.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ParcialMatriz.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ParcialMatriz.dir/clean

CMakeFiles/ParcialMatriz.dir/depend:
	cd /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/ParcialMatriz /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/Debug /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/Debug /home/juan/Escritorio/SergioArboleda/ParcialesPrimerCorte/PrimerParcial/Debug/CMakeFiles/ParcialMatriz.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ParcialMatriz.dir/depend
