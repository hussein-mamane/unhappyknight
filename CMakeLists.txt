cmake_minimum_required(VERSION 3.28)
project(UnhappyKnight)

set(CMAKE_CXX_STANDARD 11)
#link_directories(${CMAKE_SOURCE_DIR}/dlls)
add_executable(UnhappyKnight src/main.cpp
        src/Animation.cpp
        src/Animation.h
        src/Window.cpp
        src/Window.h
        src/Entity.cpp
        src/Entity.h
        src/vec2.cpp
        src/vec2.h
        src/common.h)


set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_IMAGE_PATH "SDL2Image/x86_64-w64-mingw32")
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})