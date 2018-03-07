#pragma once
#ifndef MODEL_H
#define MODEL_H

#include "File.h"

class Model
{
private:
	std::vector<File*> files;

	File* currentFile;

	int fileQuantity;

public:
	Model() {}
	~Model() {}

	void newFile(File* file) { files.push_back(file); fileQuantity++; }
	void deleteFile(File* file) { delete file; }
	void deleteAllFiles();

	File* getCurrentFile() const { return currentFile;}
	void setCurrentFile(File* file) { currentFile= file; }

	int getFileQuantity() const { return fileQuantity; }

	std::vector<File*> getFiles() const { return files; }

};
#endif // !MODEL_H
