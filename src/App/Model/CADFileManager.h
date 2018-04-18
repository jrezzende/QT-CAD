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
   CADFile* currentFile() const { return current; }
   CADFile* mementoFile() const { return memento; }
   bool redo() const { return redoFlag; }
   void setCurrentFile(CADFile* file)  { current= file; file->connectClearRedo(std::bind(&CADFileManager::clearMemento, this)); }
   void setMementoFile(CADFile* file)  { memento= file; }
   void setRedoFlag(bool flag) { redoFlag= flag; }
   void clearMemento() const { memento->eraseAllShapes(); }
   void clearShapes() const { current->eraseAllShapes(); }
   void setCanvas(Canvas& _canvas) const { currentFile()->setCanvas(_canvas); mementoFile()->setCanvas(_canvas); }
   void deleteFiles() const { delete current; delete memento; }
};

#endif //  INCLUDED_CADFILEMANAGER_H