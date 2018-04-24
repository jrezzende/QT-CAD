#pragma once
#ifndef INCLUDED_VIEWMEDIATOR_H
#define INCLUDED_VIEWMEDIATOR_H

#include "ShapeType.h"
#include "MainWindow.h"
#include "Canvas.h"

class Handler;
class MainWindow;
class Point;

enum MouseEvent
{
   PRESS,
   MOVE,
   RELEASE,
   WHEELUP,
   WHEELDOWN
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
   Handler* handler;
   MainWindow _window;

public:
   ~ViewMediator()= default;
   explicit ViewMediator(Handler* _handler) : handler(_handler), _window(this) { _window.show(); }

   Handler& manager() const { return *handler; }
   Canvas& canvas() const { return _window.canvas(); }

   std::string fileLabel(WindowActions wa);

   void sendMouseEvents(const MouseEvent me, Point& p) const;
   void sendShapeEvents(const ShapeType st) const;
   void sendMessage(std::string& s) const;
   void sendCommand(WindowActions wa) const;
   void setTitle(QString& s) { _window.setWindowTitle(s); }
   void setWindowWidget(Canvas* canvas) { _window.setCentralWidget(canvas); }
};

#endif // INCLUDED_VIEWMEDIATOR_H