
# We will call the project and the executable by the same name
set(prog_name sdl_exercise)

# Set the project name
project(${prog_name})

# Compile the source files into the executable
add_executable(${prog_name} game.cpp texture_manager.cpp game_object.cpp player.cpp main.cpp)

# Link all the disired libraries
target_link_libraries(${prog_name} sdl2 sdl2_image)
