#pragma once
#ifndef MODEL_H
#define MODEL_H

#include "File.h"

class Model
{
private:
	std::vector<File*> files;

	File* currentFile;

public:
	Model() : currentFile(nullptr) {}
	~Model() {}

	void newFile(File* file) { files.push_back(file); }
	void deleteFile(File* file) { delete file; }
	void deleteAllFiles();

	File* getCurrentFile() { return currentFile;}
	void setCurrentFile(File* file) { currentFile= file; }

	int getFileQuantity() const { return static_cast<int>(files.size()); }

	std::vector<File*> getFiles() const { return files; }

};
#endif // !MODEL_H
