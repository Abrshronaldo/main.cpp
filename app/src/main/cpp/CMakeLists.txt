


cmake_minimum_required(VERSION 3.18)
project(HelloWorldApp)

# Set output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libs/${ANDROID_ABI})

# Define the shared library
add_library(
    native-lib
    SHARED
    native-lib.cpp
)

# Locate log library
find_library(log-lib log)

# Include JNI headers
include_directories(${CMAKE_SYSROOT}/usr/include)
include_directories(${CMAKE_SYSROOT}/usr/include/jni)

# Link libraries
target_link_libraries(
    native-lib
    ${log-lib}
)
	

