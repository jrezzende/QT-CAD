#pragma once
#ifndef INCLUDED_CADFILEMANAGER_H
#define INCLUDED_CADFILEMANAGER_H

#include "CADFile.h"

class CADFileManager
{
   CADFile* current;
   CADFile* memento;

   bool redoFlag;
public:
   ~CADFileManager()= default;
   CADFileManager() : current(new CADFile("untitled")), memento(new CADFile("memento")), redoFlag(false) { current->connectClearRedo(std::bind(&CADFileManager::clearMemento, this)); }
   CADFile* getCurrentFile() const { return current; }
   CADFile* getMementoFile() const { return memento; }
   bool getRedoFlag() const { return redoFlag; }
   void setCurrentFile(CADFile* file)  { current= file; file->connectClearRedo(std::bind(&CADFileManager::clearMemento, this));}
   void setMementoFile(CADFile* file)  { memento= file; file->connectClearRedo(std::bind(&CADFileManager::clearMemento, this));}
   void setRedoFlag(bool flag) { redoFlag= flag; }
   void clearMemento() const { memento->eraseAllShapes(); }
   void clearShapes() { current->eraseAllShapes(); }
   void setCanvas(Canvas& _canvas) const { getCurrentFile()->setCanvas(_canvas); getMementoFile()->setCanvas(_canvas); }
   void deleteFiles() const { delete current; delete memento; }
};

#endif //  INCLUDED_CADFILEMANAGER_H