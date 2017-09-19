# Instructions for CMake.

message("CMake version: ${CMAKE_VERSION}")

cmake_minimum_required (VERSION 2.6)
project (Aolis)

set (Aolis_VERSION_MAJOR 0)
set (Aolis_VERSION_MINOR 1)
set (Aolis_VERSION_PATCH 0)

enable_language (CXX)
add_compile_options(-std=c++11)

#find_file (SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
#find_library (SDL2_LIBRARY NAME SDL2)
find_package (SDL2 REQUIRED)

set (EXEC run)
#set (Aolis_SOURCE_DIR src)
set (SOURCE_FILES src/main.cpp src/functions.cpp)
add_executable (${EXEC} ${SOURCE_FILES})
target_include_directories (${EXEC} PUBLIC ${SDL2_INCLUDE_DIR} include)


set (TESTING FALSE)

# Linking
if (TESTING)
  execute_process(COMMAND sdl2-config --libs
    OUTPUT_VARIABLE SDL2_LIBRARIES
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )
endif (TESTING)

# Remove trailing whitespace from linker line
string (STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries (${EXEC} ${SDL2_LIBRARIES})

if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Debug CACHE STRING
    "Build type (Can be one of: Debug Release RelWithDebInfo MinSizeRel)" FORCE)
endif (NOT CMAKE_BUILD_TYPE)
