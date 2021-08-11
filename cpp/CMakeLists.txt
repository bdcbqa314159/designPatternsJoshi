cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(dpJoshi VERSION 0.1.0)

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/dpJoshi_bits")

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/intro.hpp
    ${PROJECT_INCLUDE_DIR}/random1.hpp
    ${PROJECT_INCLUDE_DIR}/simpleMC.hpp
    ${PROJECT_INCLUDE_DIR}/payoff1.hpp
    ${PROJECT_INCLUDE_DIR}/payoff2.hpp
    ${PROJECT_INCLUDE_DIR}/vanilla1.hpp
    
    ${PROJECT_SOURCE_DIR}/intro.cpp
    ${PROJECT_SOURCE_DIR}/random1.cpp
    ${PROJECT_SOURCE_DIR}/simpleMC.cpp
    ${PROJECT_SOURCE_DIR}/payoff1.cpp
    ${PROJECT_SOURCE_DIR}/payoff2.cpp
    ${PROJECT_SOURCE_DIR}/vanilla1.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(dpJoshi SHARED ${SOURCE_FILES})

# Include directories
target_include_directories(dpJoshi PRIVATE include/dpJoshi_bits)

# Install
install(TARGETS dpJoshi DESTINATION lib)

# Install the headers
install(FILES include/dpJoshi DESTINATION include)

# Create base directory
install(DIRECTORY include/dpJoshi_bits DESTINATION include)
