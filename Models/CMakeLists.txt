# library Name
project(Models)

# add the library
add_library(Models STATIC
    Base.h
    Base.cpp
    BlackScholes.h
    Heston.h
    SABR.h
)

# Specify include directories
target_include_directories(Models PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})