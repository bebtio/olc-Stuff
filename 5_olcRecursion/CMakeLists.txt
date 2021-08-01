# Author: Alberto Heras
# Date:   1 August 2020

# Sets the compilation flags to report all warnings and enable debugging in the generated
# object files and executable.

set( CMAKE_CXX_FLAGS "-Wall -g -std=c++17" )


# The following file GLOB command will search for all files within the current directory
# that match the specified expressions (*.cpp and *.h), and assign the resulting files
# to the variable SRCS. Thus, SRCS is a list a all C source and header files in the
# current directory.

file( GLOB SRCS *.cpp *.hpp )

# Define the target application executable and the list of CPP source
# and header files needed for the executable.

## Create an executable called recursion using sources defined by GLOB command.

add_executable( recursion ${SRCS} )

## Tell CMake which libraries to use to compile the executable.

target_link_libraries( recursion  -lX11 -lGL -lpthread -lpng -lstdc++fs )

# Define include paths. Includes olcPixelGameEngine.
target_include_directories( recursion PRIVATE ${OLC_INSTALL_LOCATION}/src/olcPixelGameEngine/ )
