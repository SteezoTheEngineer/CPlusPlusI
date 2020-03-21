# Set Name of project and language
project(Ex4 LANGUAGES CXX)

# Set cmake version
cmake_minimum_required(VERSION 3.10)

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")

# Create executable using the specified source files
add_executable(Ex4Main
    ex04.cpp
    )

# Define required c++ standard to C++11
target_compile_features(Ex4Main PUBLIC cxx_std_11)

# Set compile options, enable warnings
target_compile_options(Ex4Main PRIVATE
$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
$<$<CXX_COMPILER_ID:MSVC>: /W3>
)
