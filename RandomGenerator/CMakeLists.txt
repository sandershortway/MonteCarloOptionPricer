# library Name
project(RandomGenerator)

# add the library
add_library(RandomGenerator STATIC
    RandomGenerator.h
    RandomGenerator.cpp
)

# Specify include directories
target_include_directories(RandomGenerator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})