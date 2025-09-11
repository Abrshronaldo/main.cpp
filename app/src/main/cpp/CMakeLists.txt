


cmake_minimum_required(VERSION 3.18)
project(HelloWorldApp)

# Locate JNI
find_package(Java REQUIRED)
find_package(JNI REQUIRED)

# Include JNI headers
include_directories(${JNI_INCLUDE_DIRS})

# Optional: Log library for Android (if you're building for Android)
# You can comment this out if not needed
# find_library(log-lib log)

# Define the shared library
add_library(
    native-lib
    SHARED
    native-lib.cpp
)

# Link JNI libraries (and log if needed)
target_link_libraries(
    native-lib
    ${JNI_LIBRARIES}
    # ${log-lib}
)

