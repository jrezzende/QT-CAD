#pragma once
#ifndef INCLUDED_MODEL_H
#define INCLUDED_MODEL_H

#include "CADFile.h"

class Model
{
	std::vector<CADFile*> files;

	CADFile* currentFile;
	CADFile* mementoFile;

	bool mementoFlag;
public:
	void addFile(CADFile* file);
	void deleteFile(CADFile* file) { delete &file; }
	void deleteAllFiles();

	CADFile* getCurrentFile() const { return currentFile; } // x
	CADFile* getMementoFile() const { return mementoFile; } // x

	void setCurrentFile(CADFile* file) { currentFile= file; } // x
	void setMementoFile(CADFile* file) { mementoFile= file; } // x

   void addShapeToMemento(CADShape* shape);

	void clearMemento() const { mementoFile->eraseAllShapes(); }

	void setMementoFlag(const bool flag) { mementoFlag= flag; }
	bool getMementoFlag() const { return mementoFlag; }

	int getFileQuantity() const { return static_cast<int>(files.size()); }

	std::vector<CADFile*> getFiles() const { return files; }

};

#endif //  INCLUDED_MODEL_H