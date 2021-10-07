# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("TrabalhoCores")

# Include sub-projects.
add_subdirectory ("TrabalhoCores")

# Glad
target_include_directories(TrabalhoCores PUBLIC "glad/include")

# Glfw
# Desabilita build de docs, testes e exemplos.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)