project(utilities CXX)

set(
	UTIILITIES_HEADERS
	Point.h
	ShapeType.h
	TemplateIterator.h
)

add_library(utilities STATIC ${UTIILITIES_HEADERS})

target_include_directories(utilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})