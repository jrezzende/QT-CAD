project(controller CXX)

set(
	CONTROLLER_SOURCES
	CommandArc.cpp
	CommandBezier.cpp
	CommandLine.cpp
	CommandNewFile.cpp
	CommandSetCurrentFile.cpp
	CommandLoadFile.cpp
	CommandSave.cpp
	CommandSaveAs.cpp
	CommandUndo.cpp
	CommandClear.cpp
	CommandExit.cpp
)

set(
	CONTROLLER_HEADERS
	Command.h
	CommandIdle.h
	CommandArc.h
	CommandBezier.h
	CommandLine.h
	CommandNewFile.h
	CommandSetCurrentFile.h
	CommandLoadFile.h
	CommandSave.h
	CommandSaveAs.h
	CommandUndo.h
	CommandClear.h
	CommandExit.h
	ShapeCommand.h
)

add_library(controller STATIC ${CONTROLLER_SOURCES} ${CONTROLLER_HEADERS})

target_include_directories(controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(controller domain view model)

