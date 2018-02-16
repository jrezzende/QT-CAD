project(controller CXX)

set(
	CONTROLLER_SOURCES
	Command.cpp
)

set(
	CONTROLLER_HEADERS
	Command.h
)

add_library(controller STATIC ${CONTROLLER_SOURCES} ${CONTROLLER_HEADERS})

target_include_directories(controller PUBLIC ${CONTROLLER_SOURCE_DIR})

target_link_libraries(controller domain)