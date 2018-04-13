#pragma once
#ifndef INCLUDED_VIEWMEDIATOR_H
#define INCLUDED_VIEWMEDIATOR_H

#include <string>

#include "ShapeType.h"
#include "MainWindow.h"
#include "Canvas.h"

class Manager;
class MainWindow;
class Point;

enum MouseEvent
{
   PRESS,
   MOVE,
   RELEASE
};

enum WindowActions
{
   NEW,
   LOAD,
   SAVE,
   UNDO,
   REDO,
   CLEAR,
   EXIT
};

class ViewMediator
{
   Manager* manager;
   MainWindow window;

public:
   ~ViewMediator()= default;
   ViewMediator(Manager* _manager) : manager(_manager), window(this) { window.show(); }

   Manager& getManager() const { return *manager; }

   void sendMouseEvents(MouseEvent me, Point& p) const;
   void sendShapeEvents(ShapeType st) const;
   void sendMessage(std::string& s) const;
   void sendCommand(WindowActions wa) const;

   std::string retrieveFileLabel(WindowActions wa);

   Canvas& getCanvas() const { return window.getCanvas(); }


   void setTitle(QString& s) { window.setWindowTitle(s); }
   void setWindowWidget(Canvas* canvas) { window.setCentralWidget(canvas); }
};

#endif // INCLUDED_VIEWMEDIATOR_H