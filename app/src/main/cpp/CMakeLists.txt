




cmake_minimum_required(VERSION 3.10)
project(HelloWorldApp)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use shared C++ runtime
set(ANDROID_STL c++_shared)
add_library(native-lib SHARED native-lib.cpp)

find_library(log-lib log)

target_link_libraries(native-lib PRIVATE ${log-lib})

