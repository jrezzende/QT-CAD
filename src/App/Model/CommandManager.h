#pragma once
#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

class Command;
class ShapeCommand;
class MainWindow;
class Model; 
class Point;
class Canvas;

class CommandManager
{
	Model& model;
	MainWindow& window;

	Command* command;
	ShapeCommand* shapeCommand;

	Point* firstPoint;
	Point* lastPoint;

public:
	~CommandManager();
	CommandManager(Model& m, MainWindow& w);

	void newFile();
	void saveFile();// structure commands first
	void saveAsFile();
	void openFile();// 
	void exitFile();

	void mousePressEvent(Point pos);
	void mouseReleaseEvent(Point pos);
	void mouseMoveEvent(Point pos);

	void lineCommand();
	void bezierCommand();
	void arcCommand();

	void clearShapes();
	void clearLastShape();

	ShapeCommand& getCommandShape() const { return *shapeCommand; }
	Command& getCommand() const { return *command; }

	void runCommand(Command* cmd);
};
#endif // !COMMANDMANAGER_H
