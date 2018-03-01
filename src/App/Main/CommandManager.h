#pragma once
#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

class Command;
class CommandShape;
class MainWindow;
class Model; 
class Point;
class Canvas;

class CommandManager
{
	Model& model;
	MainWindow& window;
	Command* command;
	CommandShape* commandShape;

	Point* firstPoint;
	Point* lastPoint;

public:
	~CommandManager();
	CommandManager(Model& model, MainWindow& window);

	void newFile();
	void saveFile();// structure commands first
	void openFile();// 
	void closeFile();

	void mousePressEvent(Point pos);
	void mouseReleaseEvent(Point pos);
	void mouseMoveEvent(Point pos);

	void lineCommand();
	void bezierCommand();
	void arcCommand();

	void clearShapes();
	void clearLastShape();

	CommandShape& getCommandShape() const { return *commandShape; }
	Command& getCommand() const { return *command; }

	void runCommand(Command* command);
};
#endif // !COMMANDMANAGER_H
