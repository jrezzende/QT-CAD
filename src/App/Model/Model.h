#pragma once
#ifndef MODEL_H
#define MODEL_H

#include "File.h"

class Model
{
private:
	std::vector<File*> files;

	File* currentFile;
	File* mementoFile;

	bool mementoFlag;
public:
	void addFile(File* file);
	void deleteFile(File* file) { delete file; }
	void deleteAllFiles();

	File* getCurrentFile() { return currentFile; }
	File* getMementoFile() { return mementoFile; }
	void setCurrentFile(File* file) { currentFile= file; }
	void setMementoFile(File* file) { mementoFile= file; }

	void addShapeToMemento(Shape* shape);

	void clearMemento() { mementoFile->eraseAllShapes(); }

	void setMementoFlag(bool flag) { mementoFlag= flag; }
	bool getMementoFlag() const { return mementoFlag; }

	int getFileQuantity() const { return static_cast<int>(files.size()); }

	std::vector<File*> getFiles() const { return files; }

};
#endif // !MODEL_H