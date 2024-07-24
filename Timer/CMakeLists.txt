# library Name
project(Timer)

# add the library
add_library(Timer STATIC
    Timer.h
    Timer.cpp
)

# Specify include directories
target_include_directories(Timer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})