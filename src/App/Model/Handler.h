#pragma once
#ifndef INCLUDED_HANDLER_H
#define INCLUDED_HANDLER_H

class Command;
class ShapeCommand;
class MainWindow;
class Point;
class Canvas;
class ViewMediator;

#include "CADFileManager.h"

class Handler
{
   CADFileManager& cadFileManager;
   ViewMediator* viewMediator;
   
	Command* currentCmd;
	ShapeCommand* shapeCommand;

public:
	~Handler();
	Handler(CADFileManager& m);

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

	ShapeCommand& commandShape() const { return *shapeCommand; }
	Command& command() const { return *currentCmd; }
   CADFileManager& fileManager() const { return cadFileManager; }
   ViewMediator& mediator() const { return *viewMediator; }

   bool currentFileStatus() const { return cadFileManager.currentFile().status(); }
   std::vector<std::shared_ptr<CADShape>> currentFileShapes() const { return cadFileManager.currentFile().shapesVector(); }

   void sendMessageToStatusBar(std::string& msg) const;
	void runCommand(Command* cmd);
};

#endif //  INCLUDED_HANDLER_H
