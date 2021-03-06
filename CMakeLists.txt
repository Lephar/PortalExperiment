cmake_minimum_required(VERSION 3.17)
project(Portal)

set(CMAKE_CXX_STANDARD 20)

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/shaders)
add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/shaders/vert.spv COMMAND glslc ${PROJECT_SOURCE_DIR}/shaders/shader.vert -o ${PROJECT_BINARY_DIR}/shaders/vert.spv -O)
add_custom_command(OUTPUT ${PROJECT_BINARY_DIR}/shaders/frag.spv COMMAND glslc ${PROJECT_SOURCE_DIR}/shaders/shader.frag -o ${PROJECT_BINARY_DIR}/shaders/frag.spv -O)
add_custom_target(Shaders ALL DEPENDS ${PROJECT_BINARY_DIR}/shaders/vert.spv ${PROJECT_BINARY_DIR}/shaders/frag.spv)

file(COPY ${PROJECT_SOURCE_DIR}/models DESTINATION ${PROJECT_BINARY_DIR})
add_custom_target(Models ALL DEPENDS ${PROJECT_BINARY_DIR}/models)

add_executable(Portal Main.cpp)
add_dependencies(Portal Shaders)
target_precompile_headers(Portal PRIVATE Main.hpp)
target_include_directories(Portal PRIVATE headers)
target_link_libraries(Portal glfw vulkan)
