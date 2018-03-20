project(domain CXX)

set(
	DOMAIN_SOURCES
	Arc.cpp
	Bezier.cpp
	Line.cpp
	File.cpp
)

set(
	DOMAIN_HEADERS
	Point.h
	Shape.h
	Arc.h
	Bezier.h
	Line.h
	File.h
	ShapeType.h
)

add_library(domain STATIC ${DOMAIN_SOURCES} ${DOMAIN_HEADERS})

target_include_directories(domain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(domain view)