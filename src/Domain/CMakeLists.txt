project(domain CXX)

set(
	DOMAIN_SOURCES
	CADArc.cpp
	CADBezier.cpp
	CADLine.cpp
	CADFile.cpp
)

set(
	DOMAIN_HEADERS
	CADShape.h
	CADArc.h
	CADBezier.h
	CADLine.h
	CADFile.h
)

add_library(domain STATIC ${DOMAIN_SOURCES} ${DOMAIN_HEADERS})

target_include_directories(domain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(domain view model utilities)