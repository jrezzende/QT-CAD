#pragma once
#ifndef INCLUDED_VIEWMEDIATOR_H
#define INCLUDED_VIEWMEDIATOR_H

#include "ShapeType.h"
#include "MainWindow.h"
#include "Canvas.h"

class CommandHandler;
class MainWindow;
class Point;

enum MouseEvent
{
   PRESS,
   MOVE,
   RELEASE,
   WHEEL,
   TRACKING
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
   CommandHandler* handler;
   MainWindow _window;

public:
   ~ViewMediator()= default;
   explicit ViewMediator(CommandHandler* _handler) : handler(_handler), _window(this) { _window.show(); }

   CommandHandler& manager() const { return *handler; }
   Canvas& canvas() const { return _window.canvas(); }

   std::string fileLabel(WindowActions wa);

   void sendMouseEvents(const MouseEvent me, Point& p) const;
   void sendShapeEvents(const ShapeType st) const;
   void sendMouseMessages(const MouseEvent me, const Point& p) const;
   void sendDeltaFactor(const int factor);
   void sendMessage(std::string msg);
   void sendCommand(const WindowActions wa) const;
   void setTitle(QString& s) { _window.setWindowTitle(s); }
   void setWindowWidget(Canvas* canvas) { _window.setCentralWidget(canvas); }
};

#endif // INCLUDED_VIEWMEDIATOR_H