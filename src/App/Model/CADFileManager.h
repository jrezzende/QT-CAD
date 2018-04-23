#pragma once
#ifndef INCLUDED_CADFILEMANAGER_H
#define INCLUDED_CADFILEMANAGER_H

#include <memory>

#include "CADFile.h"

class CADFileManager
{
   CADFile* current;
   CADFile* memento;

   bool redoFlag;

public:
   ~CADFileManager()= default;
   CADFileManager() : 
   current(new CADFile("untitled")), 
   memento(new CADFile("memento")), redoFlag(false)
   { current->connectClearRedo(std::bind(&CADFileManager::clearMemento, this)); }

   CADFile& currentFile() const { return *current; }
   CADFile& mementoFile() const { return *memento; }

   bool redo() const { return redoFlag; }

   void setCurrentFile(CADFile* file)  { 
      file->connectClearRedo(std::bind(&CADFileManager::clearMemento, this));  current= file;  }
   void setMementoFile(CADFile* file)  { memento= file; }
   void setRedoFlag(bool flag) { redoFlag= flag; }
   void setCanvas(Canvas& _canvas) const { current->setCanvas(_canvas); memento->setCanvas(_canvas); }

   void clearMemento() const { memento->eraseAllShapes(); }
   void clearShapes() const { current->eraseAllShapes(); }
};

#endif //  INCLUDED_CADFILEMANAGER_H