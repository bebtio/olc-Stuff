file( GLOB SRCS *.cpp *.h )

SET(CMAKE_CXX_FLAGS "-std=c++0x")
add_executable( mmbnMap ${SRCS} )

## Tell CMake which libraries to use to compile the executable.

target_link_libraries( mmbnMap  -lX11 -lGL -lpthread -lpng -lstdc++fs )

# Define include paths. Includes olcPixelGameEngine.
target_include_directories( battleship PRIVATE ${EXTERNAL_INSTALL_LOCATION}/src/olcPixelGameEngine/ )
