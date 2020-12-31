
cmake_minimum_required(VERSION 2.8.8)

find_package(Git REQUIRED)

# Handle external dependency repositories here.

## Required for cmake to know to checkout externals.
include(ExternalProject)

## Set the location of the exteranal repos.
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

## Give commands to checkout the repos.
ExternalProject_Add(
    olcPixelGameEngine
    PREFIX ${EXTERNAL_INSTALL_LOCATION}
    GIT_REPOSITORY https://github.com/OneLoneCoder/olcPixelGameEngine.git
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

# Define project and executable stuff here.

## Give project name.
project( olcStuff )

## Define sources for executable.
add_subdirectory( 1_UserInputDisplay )
