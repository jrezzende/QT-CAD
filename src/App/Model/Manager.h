#pragma once
#ifndef INCLUDED_MANAGER_H
#define INCLUDED_MANAGER_H

class Command;
class ShapeCommand;
class MainWindow;
class Point;
class Canvas;
class ViewMediator;

#include <string>

#include "CADFileManager.h"

class Manager
{
   CADFileManager& fileManager;
   ViewMediator* mediator;
   
	Command* command;
	ShapeCommand* shapeCommand;

public:
	~Manager();
	Manager(CADFileManager& m);

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
   CADFileManager& getFileManager() const { return fileManager; }
   ViewMediator& getMediator() const { return *mediator; }

   bool getCurrentFileStatus() const { return fileManager.getCurrentFile()->getStatus(); }
   std::vector<CADShape*> getCurrentFileShapes() const { return fileManager.getCurrentFile()->getShapes(); }

   void sendMessageToStatusBar(std::string& msg) const;
	void runCommand(Command* cmd);
};

#endif //  INCLUDED_MANAGER_H
