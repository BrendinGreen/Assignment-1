cmake_minimum_required(VERSION 3.7)
project(Patients)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES WICPS.cpp List.cpp Patient.cpp)
add_executable(Patients ${SOURCE_FILES})