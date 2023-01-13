cmake_minimum_required(VERSION 3.15)
project(Raycasting)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(Raycasting main.cpp FieldOfView.cpp FieldOfView.h)

set(SFML_DIR "D:\\JetBrains\\CLion projects\\lib\\sfml\\GCC 7.3.0 MinGW (SEH) - 64-bit\\SFML-2.5.1\\lib\\cmake\\SFML")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

target_link_libraries(Raycasting sfml-graphics)