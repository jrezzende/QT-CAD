project(view CXX)

set(
	VIEW_SOURCES
	MainWindow.cpp
	Canvas.cpp
)

set(
	VIEW_HEADERS
	MainWindow.h
	Canvas.h
)

add_library(view STATIC ${VIEW_HEADERS} ${VIEW_SOURCES})

target_include_directories(view PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
					view domain
					Qt5::Gui
					Qt5::Widgets
)