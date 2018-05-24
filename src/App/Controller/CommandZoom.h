#pragma once
#ifndef INCLUDED_COMMANDZOOM_H
#define INCLUDED_COMMANDZOOM_H

#include "Command.h"

class PointMapper;

class CommandZoom : public Command
{
   PointMapper& mapper;

public:
   ~CommandZoom()= default;
   CommandZoom(PointMapper* p) : mapper(*p) {}
   
   void execute(CADFileManager& fmanager, ViewMediator& vmediator);
};

#endif // INCLUDED_COMMANDZOOM_H