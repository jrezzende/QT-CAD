project(model CXX)

set(
	MODEL_SOURCES
	Handler.cpp
	ShapeVisitorSaveFile.cpp
	ViewMediator.cpp
)

set(
	MODEL_HEADERS
	Handler.h
	CADFileManager.h
	ShapeVisitor.h
	ShapeVisitorSaveFile.h
	ViewMediator.h
)

add_library(model STATIC ${MODEL_SOURCES} ${MODEL_HEADERS})

target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(model domain controller)

