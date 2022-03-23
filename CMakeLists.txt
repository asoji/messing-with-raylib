cmake_minimum_required(VERSION 3.16)
project(messing-with-raylib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib 4.0.0 REQUIRED)

add_executable(messing-with-raylib
        "src/main.cpp"
        "src/main.hpp")

target_include_directories(messing-with-raylib PRIVATE ${RAYLIB_INCLUDE_DIRS})

target_link_libraries(messing-with-raylib
        ${RAYLIB_LIBRARIES})