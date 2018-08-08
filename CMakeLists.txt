cmake_minimum_required(VERSION 3.9)
project(untitled2)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled2

        main.cpp

        file_huffman.cpp
        file_huffman.h

        huffman.cpp
        huffman.h

        file_reader.cpp
        file_reader.h
        file_writer.cpp
        file_writer.h

        reader.h
        writer.h)
