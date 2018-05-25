project(controller CXX)

set(
	CONTROLLER_SOURCES
	CommandIdle.cpp
	CommandArc.cpp
	CommandBezier.cpp
	CommandLine.cpp
	CommandZoom.cpp
	CommandNewFile.cpp
	CommandLoadFile.cpp
	CommandSave.cpp
	CommandUndo.cpp
	CommandRedo.cpp
	CommandClear.cpp
	CommandTranslateCanvas.cpp
	CommandExit.cpp
)

set(
	CONTROLLER_HEADERS
	Command.h
	CommandIdle.h
	CommandArc.h
	CommandBezier.h
	CommandLine.h
	CommandZoom.h
	CommandNewFile.h
	CommandLoadFile.h
	CommandSave.h
	CommandUndo.h
	CommandRedo.h
	CommandClear.h
	CommandExit.h
	CommandTranslateCanvas.h
	ShapeCommand.h
)

add_library(controller STATIC ${CONTROLLER_SOURCES} ${CONTROLLER_HEADERS})

target_include_directories(controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(controller domain view model)

