cmake_minimum_required(VERSION 3.14)

project(SocketLibCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
	set(PLATFORM_DIR "windows")
else()
	set(PLATFORM_DIR "linux")
endif()

file(GLOB_RECURSE SOCKET_SOURCES ${PROJECT_SOURCE_DIR}/socket/${PLATFORM_DIR}/*.cpp)
file(GLOB_RECURSE SOCKET_INCLUDE ${PROJECT_SOURCE_DIR}/socket/*.hpp)

add_library(${PROJECT_NAME} STATIC
	utils/socket_exception.hpp	
	utils/defines.hpp
	${SOCKET_SOURCES}
	${SOCKET_INCLUDE}
)

target_link_libraries(${PROJECT_NAME} ssl crypto)

target_include_directories(${PROJECT_NAME} PUBLIC socket/)

target_include_directories(${PROJECT_NAME} PUBLIC utils/)