
cmake_minimum_required(VERSION 3.21)

project (Aolis VERSION 0.1.0)

set (Aolis_VERSION_MAJOR 0)
set (Aolis_VERSION_MINOR 1)
set (Aolis_VERSION_PATCH 0)

include(FindPkgConfig)

find_package(SDL2 REQUIRED)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

file(GLOB APP_SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(run ${APP_SRC})

target_include_directories(run PRIVATE
	"${PROJECT_SOURCE_DIR}/include"
	"${SDL2_INCLUDE_DIR}"
	"${SDL2IMAGE_INCLUDE_DIR}"
	"${SDL2MIXER_INCLUDE_DIR}"
)

target_link_libraries(run PRIVATE
	${SDL2_LIBRARIES}
	${SDL2IMAGE_LIBRARIES}
	${SDL2MIXER_LIBRARIES}
)
