cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME_STR util)
project(${PROJECT_NAME_STR} CXX)

set(CMAKE_CXX_STANDARD 11)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
   # Mac OS X specific code
   set(OS "Mac OS X")
   set(MACOSX TRUE)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
   # Mac OS X specific code
   set(OS "Linux")
   set(LINUX TRUE)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
   # Mac OS X specific code
   set(OS "Windows")
   set(WINDOWS TRUE)
else()
	set(OS "Unknown")
endif()

message(STATUS "DETECTED OS: ${OS}")

#Use solution folders. 
set_property(GLOBAL PROPERTY USE_FOLDERS ON) 

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE HEADERS src/*.h)

#-------------------
# Module source
#-------------------
set(SOURCES
	src/stringfmt.cpp
	)

add_library(${PROJECT_NAME_STR} ${SOURCES} ${HEADERS})

#add_library(${PROJECT_NAME_STR}_static STATIC $<TARGET_OBJECTS:${PROJECT_NAME_STR}_obj>)
#add_library(${PROJECT_NAME_STR} SHARED $<TARGET_OBJECTS:${PROJECT_NAME_STR}_obj>)
