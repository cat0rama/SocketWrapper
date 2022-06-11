cmake_minimum_required(VERSION 3.14)

project(SocketWrapper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#if(WIN32)
	#set(PLATFORM_DIR "windows")
#else()
	#set(PLATFORM_DIR "linux")
#endif()

file(GLOB_RECURSE SOCKET_INCLUDE ${PROJECT_SOURCE_DIR}/socket/*.hpp)
file(GLOB_RECURSE SOCKET_SOURCES ${PROJECT_SOURCE_DIR}/socket/src/*.cpp)

file(GLOB_RECURSE UTILS_INCLUDE ${PROJECT_SOURCE_DIR}/utils/*.hpp)
file(GLOB_RECURSE UTILS_SOURCE ${PROJECT_SOURCE_DIR}/utils/src/*.cpp)

add_library(${PROJECT_NAME} STATIC
	${UTILS_INCLUDE}
	${UTILS_SOURCE}
	${SOCKET_INCLUDE}
	${SOCKET_SOURCES}
)

target_link_libraries(${PROJECT_NAME} ssl crypto)

target_include_directories(${PROJECT_NAME} PUBLIC socket/)

target_include_directories(${PROJECT_NAME} PUBLIC utils/)
