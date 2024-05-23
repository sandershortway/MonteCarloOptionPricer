cmake_minimum_required(VERSION 3.10)

project(MonteCarloOptionPricer VERSION 1.0)

include_directories(include)

set(SOURCES
    src/Main.cpp
    src/Models.cpp
    src/RandomNormalGenerator.cpp
    src/Timer.cpp
)

set(HEADERS
    include/Models.h
    include/RandomNormalGenerator.h
    include/Timer.h
)

add_executable(MonteCarloOptionPricing ${SOURCES} ${HEADERS})