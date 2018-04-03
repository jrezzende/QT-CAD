#pragma once
#ifndef INCLUDED_COMMANDMANAGER_H
#define INCLUDED_COMMANDMANAGER_H

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

	void newFileCmd();
	void saveFileCmd();
	void loadFileCmd();
	void exitFileCmd();

	void mousePressEvent(const Point& pos);
	void mouseReleaseEvent(const Point& pos);
	void mouseMoveEvent(const Point& pos);

	void lineCommand();
	void bezierCommand();
	void arcCommand();

	void clearShapes();
	void eraseLastShape();
	void redoShape();

	ShapeCommand& getCommandShape() const { return *shapeCommand; }
	Command& getCommand() const { return *command; }
	Model& getModel() const { return model; }
	MainWindow& getWindow() const { return window; }

	void runCommand(Command* cmd);
};

#endif //  INCLUDED_COMMANDMANAGER_H
