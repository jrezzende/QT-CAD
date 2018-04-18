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
   Manager* _manager;
   MainWindow _window;

public:
   ~ViewMediator()= default;
   ViewMediator(Manager* _manager) : _manager(_manager), _window(this) { _window.show(); }

   Manager& manager() const { return *_manager; }
   Canvas& canvas() const { return _window.canvas(); }

   std::string retrieveFileLabel(WindowActions wa);

   void sendMouseEvents(MouseEvent me, Point& p) const;
   void sendShapeEvents(ShapeType st) const;
   void sendMessage(std::string& s) const;
   void sendCommand(WindowActions wa) const;
   void setTitle(QString& s) { _window.setWindowTitle(s); }
   void setWindowWidget(Canvas* canvas) { _window.setCentralWidget(canvas); }
};

#endif // INCLUDED_VIEWMEDIATOR_H