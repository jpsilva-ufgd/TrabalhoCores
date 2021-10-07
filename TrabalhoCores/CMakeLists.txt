# CMakeList.txt : CMake project for TrabalhoCores, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (TrabalhoCores "TrabalhoCores.cpp" "Shader.h" "Shader.cpp" "Triangle/Triangle.h" "Triangle/Triangle.cpp")

include_directories(".")

# Shaders.
configure_file("Triangle/Triangle.vert" "Shaders/Triangle.vert" COPYONLY)
configure_file("Triangle/Triangle.frag" "Shaders/Triangle.frag" COPYONLY)

# TODO: Add tests and install targets if needed.

# Glad
target_sources(TrabalhoCores PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../glad/src/glad.c")

# Glfw
target_link_libraries(TrabalhoCores glfw)