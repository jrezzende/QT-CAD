cmake_minimum_required(VERSION 3.9)

project(Cad CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_PREFIX_PATH "C:/Qt/5.10.0/msvc2017_64/lib/cmake")
		
SET(CAD_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
		
add_subdirectory(src/App)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)