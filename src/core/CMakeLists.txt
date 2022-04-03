cmake_minimum_required(VERSION 3.14)

project(SocketLibCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
	set(PLATFORM_DIR "windows")		
else()
	set(PLATFORM_DIR "linux")
endif()

file(GLOB_RECURSE CLIENT_SOURCE ${PROJECT_SOURCE_DIR}/client/platform/${PLATFORM_DIR}/*.cpp)
file(GLOB_RECURSE CLIENT_INCLUDE ${PROJECT_SOURCE_DIR}/client/platform/${PLATFORM_DIR}/*.hpp)

file(GLOB_RECURSE SERVER_SOURCE ${PROJECT_SOURCE_DIR}/server/platform/${PLATFORM_DIR}/*.cpp)
file(GLOB_RECURSE SERVER_INCLUDE ${PROJECT_SOURCE_DIR}/server/platform/${PLATFORM_DIR}/*.hpp)

add_library(${PROJECT_NAME} STATIC
	${PROJECT_SOURCE_DIR}/client/platform/IClient.hpp
	${PROJECT_SOURCE_DIR}/server/platform/IServer.hpp
	${PROJECT_SOURCE_DIR}/defines/defines.hpp
	${CLIENT_SOURCE}
	${CLIENT_INCLUDE}
	${SERVER_SOURCE}
	${SERVER_INCLUDE}
)

target_link_libraries(${PROJECT_NAME} ssl crypto)

target_include_directories(${PROJECT_NAME} PUBLIC client/platform/${PLATFORM_DIR}/include)

target_include_directories(${PROJECT_NAME} PUBLIC server/platform/${PLATFORM_DIR}/include)

target_include_directories(${PROJECT_NAME} PRIVATE server/platform)

target_include_directories(${PROJECT_NAME} PRIVATE client/platform)

target_include_directories(${PROJECT_NAME} PRIVATE defines/)