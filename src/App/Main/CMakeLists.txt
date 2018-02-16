project(app CXX)

set (
	APP_SOURCES
	main.cpp
	App.cpp
)

set (
	APP_HEADERS
	App.h
)

#find_package(Qt5Widgets CONFIG 
#			 PATHS C:/Qt/5.10.0/msvc2017_64/lib/cmake/Qt5Widgets
#			 NO_DEFAULT_PATH)			 
#list(APPEND THIRD_PARTYS_LIBS Qt5::Core Qt5::Widgets)
			

add_executable(app ${APP_SOURCES} ${APP_HEADERS})

set_target_properties(app PROPERTIES ENABLE_EXPORTS 1)

target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(app view
							Qt5::Core
							Qt5::Widgets
							Qt5::Gui
							)
							
							