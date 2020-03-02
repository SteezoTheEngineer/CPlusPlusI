# Set Name of project and language
project(Ex2 LANGUAGES CXX)

# Set cmake version
cmake_minimum_required(VERSION 3.10)

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")



# Create executable using the specified source files
add_executable(Function
    functionMain.cpp
    calculatorPrint.cpp
    calculatorPrint.h
    )

# Define required c++ standard to C++11
target_compile_features(Function PUBLIC cxx_std_11)

# Set compile options, enable warnings
target_compile_options(Function PRIVATE
$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
$<$<CXX_COMPILER_ID:MSVC>: /W3>
)




# Create executable using the specified source files
add_executable(ComputePi
        computePiMain.cpp
        )

# Define required c++ standard to C++11
target_compile_features(ComputePi PUBLIC cxx_std_11)

# Set compile options, enable warnings
target_compile_options(ComputePi PRIVATE
$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
$<$<CXX_COMPILER_ID:MSVC>: /W3>
)