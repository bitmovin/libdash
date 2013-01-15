cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_MODULE_PATH})

find_package(SDL REQUIRED)
find_package(LibAV REQUIRED)

include_directories(source)

file(GLOB_RECURSE sampleplayer_source *.cpp)

add_executable(sampleplayer ${sampleplayer_source})
target_link_libraries(sampleplayer dash ${SDL_LIBRARY} ${LIBAV_LIBRARIES})