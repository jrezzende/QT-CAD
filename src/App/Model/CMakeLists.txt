project(model CXX)

set(
	MODEL_SOURCES
	Model.cpp
	CommandManager.cpp
)

set(
	MODEL_HEADERS
	Model.h
	CommandManager.h
)

add_library(model STATIC ${MODEL_SOURCES} ${MODEL_HEADERS})

target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(model domain controller)

