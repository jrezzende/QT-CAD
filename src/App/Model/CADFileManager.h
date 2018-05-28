#pragma once
#ifndef INCLUDED_CADFILEMANAGER_H
#define INCLUDED_CADFILEMANAGER_H

#include "CADFile.h"

class CADFileManager
{
   CADFile* current_;
   CADFile* stash_;

   bool redoFlag;

public:
   ~CADFileManager()= default;
   CADFileManager() : 
   current_(new CADFile("untitled")), stash_(new CADFile("stashFile")), redoFlag(false)
   { current_->connectClearRedo(std::bind(&CADFileManager::clearStash, this)); }

   CADFile& current() const { return *current_; }
   CADFile& stash() const { return *stash_; }

   bool redo() const { return redoFlag; }

   void setCurrentFile(CADFile* file)  { 
      file->connectClearRedo(std::bind(&CADFileManager::clearStash, this));  current_ = file;  }
   void setStashFile(CADFile* file)  { stash_ = file; }
   void setRedoFlag(bool flag) { redoFlag= flag; }
   void setCanvas(Canvas& _canvas) const { current_->setCanvas(_canvas); stash_->setCanvas(_canvas); }

   void clearStash() const { stash_->eraseAllShapes(); }
   void clearShapes() const { current_->eraseAllShapes(); }
};

#endif //  INCLUDED_CADFILEMANAGER_H