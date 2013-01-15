cmake_minimum_required(VERSION 2.8)


file(GLOB_RECURSE networkpart_source *.cpp)

add_executable(libdash_networkpart_test ${networkpart_source})
target_link_libraries(libdash_networkpart_test dash)