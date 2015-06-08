# Teawolf

# We will call the project and the executable by the same name
set(prog_name sdl_exercise)

# Set the project name
project(${prog_name})

# Add support for c++11 if possible
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	message(STATUS "${CMAKE_CXX_COMPILER} supports c++11, added -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
	message(STATUS "${CMAKE_CXX_COMPILER} doesn't support full c++11, added -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# Compile the source files into the executable
add_executable(${prog_name}
	game.cpp
	texture_manager.cpp
	input_handler.cpp

	vector_2d.cpp

	object_load_parameters.cpp
	sdl_game_object.cpp
	player.cpp

	main.cpp
)

# Link all the disired libraries
target_link_libraries(${prog_name} sdl2 sdl2_image)
