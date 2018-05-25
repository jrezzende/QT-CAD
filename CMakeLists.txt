cmake_minimum_required(VERSION 3.9)

project(Cad CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
		
SET(CAD_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Qt5Widgets CONFIG 
			 PATHS C:/Qt/5.10.0/msvc2017_64/lib/cmake/Qt5Widgets
			 NO_DEFAULT_PATH)
			 
list(APPEND THIRD_PARTYS_LIBS Qt5::Core Qt5::Widgets)
		
add_subdirectory(src/App/Controller)
add_subdirectory(src/App/Main)
add_subdirectory(src/App/Model)
add_subdirectory(src/App/View)

add_subdirectory(src/Domain)
add_subdirectory(src/Utilities)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)