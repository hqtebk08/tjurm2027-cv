cmake_minimum_required(VERSION 3.5)
project(tjurm-cv)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -O3 -g")

file(GLOB_RECURSE sources "src/*.cpp")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(tjurm-cv main.cpp ${sources})
target_link_libraries( tjurm-cv ${OpenCV_LIBS} )