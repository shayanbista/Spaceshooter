cmake_minimum_required(VERSION 3.10)

# Project name
project(SpaceShooterGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find SDL2 and SDL2_image packages using pkg-config
find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)


# Include directories
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


# Add executable
add_executable(${PROJECT_NAME} main.cpp map.cpp sdl.cpp player.cpp enemy.cpp game.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# Optional: Print SDL2 and SDL2_image version
message(STATUS "SDL2 Version: ${SDL2_VERSION}")
message(STATUS "SDL2_image Version: ${SDL2_IMAGE_VERSION}")
