#pragma once
#ifndef INCLUDED_COMMANDZOOM_H
#define INCLUDED_COMMANDZOOM_H

#include "Command.h"

class Point;
class Rect;

class CommandZoom : public Command
{
   float zoomFactor;

public:
   ~CommandZoom()= default;
   CommandZoom(float zf) : zoomFactor(zf) {}
   
   void execute(CADFileManager& fmanager, ViewMediator& vmediator);
};

#endif // INCLUDED_COMMANDZOOM_H