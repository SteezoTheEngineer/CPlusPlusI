# Set Name of project and language
project(SelfEvaluation LANGUAGES CXX)

# Set cmake version
cmake_minimum_required(VERSION 3.0)

# Global Settings
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable using the specified source files
add_executable(Q01 q1.cpp)
add_executable(Q02 q2.cpp)


if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()



