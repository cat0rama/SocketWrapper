cmake_minimum_required(VERSION 3.14)

project(SocketLib)

add_subdirectory(src/core)

add_subdirectory(vendor/openssl-cmake)

add_subdirectory(example)
