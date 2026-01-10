cmake_minimum_required(VERSION 3.16)
project(Tetris_2_0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(third_party/glfw)

# GLAD (ONLY glad.c here)
add_library(glad STATIC
        third_party/glad/src/glad.c
)
target_include_directories(glad PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/glad/include
)

# Your app
add_executable(Tetris_2_0
        src/main.cpp
        src/view/Window.cpp
        src/view/Renderer.cpp
        src/model/Game.cpp
        src/controller/Input.cpp
        src/model/GameObject.cpp
        src/model/GameObject.h
        src/model/Borad.cpp
        src/model/Borad.h
        src/view/BoardGameObject.cpp
        src/view/BoardGameObject.h
        # add other .cpp files here
)

# So you can include headers from src/...
target_include_directories(Tetris_2_0 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

find_package(OpenGL REQUIRED)
target_link_libraries(Tetris_2_0 PRIVATE glfw glad OpenGL::GL)
