cmake_minimum_required(VERSION 2.8)

include_directories(libxml2/include)
include_directories(libdash/include)
include_directories(sdl/include)
include_directories(zlib/include)
include_directories(iconv/include)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(libdash)
add_subdirectory(libdash_networkpart_test)