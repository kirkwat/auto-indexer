cmake_minimum_required(VERSION 3.14)
project(auto-indexer)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_DEBUG "-O3")

add_executable(auto-indexer src/main.cpp src/DSList.h src/DSVector.h src/test.cpp src/DSString.cpp src/DSString.h src/Indexer.cpp src/Indexer.h src/Keyword.cpp src/Keyword.h)
