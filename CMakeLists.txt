cmake_minimum_required(VERSION 3.21)
project(SilverLakeDB)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_OSX_ARCHITECTURES "arm64")

add_executable(SilverLakeDB main.cpp src/Tokenize.cpp header/Tokenize.h src/Utils.cpp)
