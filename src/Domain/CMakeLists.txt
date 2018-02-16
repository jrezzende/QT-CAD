project(domain CXX)

set(
	DOMAIN_SOURCES
	Line.cpp
	Bezier.cpp
	Painter.cpp
)

set(
	DOMAIN_HEADERS
	Shapes.h
	Line.h
	Bezier.h
	Painter.h
)

add_library(domain STATIC ${DOMAIN_SOURCES} ${DOMAIN_HEADERS})

target_include_directories(domain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(domain view)

