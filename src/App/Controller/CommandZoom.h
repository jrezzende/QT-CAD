#pragma once
#ifndef INCLUDED_COMMANDZOOM_H
#define INCLUDED_COMMANDZOOM_H

#include "Command.h"

class PointMapper;

class CommandZoom : public Command
{
   PointMapper& mapper;

public:
   virtual ~CommandZoom()= default;
   CommandZoom(PointMapper* pointMapper) : mapper(*pointMapper) {}
   
   void execute(CADFileManager& fileManager, ViewMediator& viewMediator);
};

#endif // INCLUDED_COMMANDZOOM_H