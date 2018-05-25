#pragma once
#ifndef INCLUDED_COMMANDHANDLER_H
#define INCLUDED_COMMANDHANDLER_H

class Command;
class ShapeCommand;
class MainWindow;
class Point;
class Canvas;
class ViewMediator;
class PointMapper;

#include "CADFileManager.h"
#include "PointMapper.h"

class CommandHandler
{
   CADFileManager& cadFileManager;
   ViewMediator* viewMediator;

   Command* currentCmd;
   ShapeCommand* shapeCommand;

   PointMapper* mapper;

   bool dragging;

public:
   ~CommandHandler();
   explicit CommandHandler(CADFileManager& m);

   void createNewFileCmd();
   void createSaveFileCmd();
   void createLoadFileCmd();
   void createExitFileCmd();

   void createZoomCmd();

   void mousePressEvent(const Point& pos);
   void rightClickEvent(const Point& pos);
   void mouseReleaseEvent(const Point& pos);
   void mouseMoveEvent(const Point& pos);

   void createLineCommand();
   void createBezierCommand();
   void createArcCommand();

   void clearShapes();
   void eraseLastShape();
   void redoShape();

   ShapeCommand& commandShape() const { return *shapeCommand; }
   Command& command() const { return *currentCmd; }
   CADFileManager& fileManager() const { return cadFileManager; }
   ViewMediator& mediator() const { return *viewMediator; }
   PointMapper& pointMapper() const { return *mapper; }

   void resetMapper() { mapper->reset(); }

   bool currentFileStatus() const { return cadFileManager.currentFile().status(); }
   std::vector<CADShape*> currentFileShapes() const { return cadFileManager.currentFile().shapesVector(); }

   void sendMessageToStatusBar(std::string& msg) const;
	void runCommand(Command* cmd);
};

#endif //  INCLUDED_COMMANDHANDLER_H
