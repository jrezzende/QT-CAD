#pragma once
#ifndef INCLUDED_CADFILEMANAGER_H
#define INCLUDED_CADFILEMANAGER_H

#include "CADFile.h"

class CADFileManager
{
   CADFile* current;
   CADFile* stashFile;

   bool redoFlag;

public:
   ~CADFileManager()= default;
   CADFileManager() : 
   current(new CADFile("untitled")), 
   stashFile(new CADFile("stashFile")), redoFlag(false)
   { current->connectClearRedo(std::bind(&CADFileManager::clearStash, this)); }

   CADFile& currentFile() const { return *current; }
   CADFile& stash() const { return *stashFile; }

   bool redo() const { return redoFlag; }

   void setCurrentFile(CADFile* file)  { 
      file->connectClearRedo(std::bind(&CADFileManager::clearStash, this));  current= file;  }
   void setStashFile(CADFile* file)  { stashFile = file; }
   void setRedoFlag(bool flag) { redoFlag= flag; }
   void setCanvas(Canvas& _canvas) const { current->setCanvas(_canvas); stashFile->setCanvas(_canvas); }

   void clearStash() const { stashFile->eraseAllShapes(); }
   void clearShapes() const { current->eraseAllShapes(); }
};

#endif //  INCLUDED_CADFILEMANAGER_H