cmake_minimum_required(VERSION 4.1)
project(Graphics)

set(CMAKE_CXX_STANDARD 23)
add_executable(Graphics src/main.cpp
        src/engine/Window.h
        src/engine/Engine.h
        src/engine/Engine.cpp
        src/math/vec3.h
        src/engine/Renderer.cpp
        src/engine/Renderer.h
        src/math/vec2.h
        src/engine/Window.cpp
        src/math/tri.h
        src/math/mesh.h
        src/math/cube.h
)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(Graphics PRIVATE SDL3::SDL3)