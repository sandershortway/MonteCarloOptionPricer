# root CMakeLists.txt file
cmake_minimum_required(VERSION 3.10)

# specify project name and version
project(MonteCarloOptionPricer VERSION 1.0)

# add subdirectories
add_subdirectory(Models)
add_subdirectory(RandomGenerator)
add_subdirectory(Timer)

# add the main executable
add_executable(MonteCarloOptionPricer Main.cpp)

# set the startup project for Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MonteCarloOptionPricer)

# link the libraries to the main executable
target_link_libraries(MonteCarloOptionPricer PRIVATE Models)
target_link_libraries(MonteCarloOptionPricer PRIVATE RandomGenerator)
target_link_libraries(MonteCarloOptionPricer PRIVATE Timer)