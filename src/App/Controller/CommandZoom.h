#pragma once
#ifndef INCLUDED_COMMANDZOOM_H
#define INCLUDED_COMMANDZOOM_H

#include "Command.h"

class Point;
class Rect;

class CommandZoom : public Command
{
   Point& focus;
   float zoomFactor;

public:
   ~CommandZoom()= default;
   CommandZoom(Point& _focus, float _zf) : focus(_focus), zoomFactor(_zf) {}
   
   void execute(CADFileManager& fmanager, ViewMediator& vmediator);
};

#endif // INCLUDED_COMMANDZOOM_H