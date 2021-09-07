# CMakeLists.txt
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

project(openhh)

set(CMAKE_CXX_STANDARD 20)

include( "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

find_package(sdl2 CONFIG REQUIRED)

set( BGFX_BUILD_EXAMPLES OFF CACHE BOOL "Build bgfx examples.")
set( BGFX_BUILD_TOOLS OFF CACHE BOOL "Build bgfx tools.")

add_subdirectory (thirdparty/bgfx.cmake)
add_subdirectory (thirdparty/HedgeLib)
add_subdirectory (thirdparty/SDLXX)
add_subdirectory (thirdparty/pugixml)

add_subdirectory (src)