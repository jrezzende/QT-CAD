#pragma once
#ifndef FILE_H
#define FILE_H

#include "Shape.h"

#include <string>

class Canvas;

enum Status
{
	NOTSAVED,
	SAVED
};

class File
{
	std::string fileName;
	std::string filePath;
	std::vector<Shape*> shapes;

	Status status;

	Canvas* canvas;
public:
	~File() {}
	File(const std::string _fileName, const Canvas* _canvas) : fileName(_fileName), 
		status(SAVED) {}

	bool getStatus() { return status; } 
	void setStatus(Status _status) { status= _status; }

	std::string getFileName() const { return fileName; }
	void setFileName(const std::string _fileName) { fileName= _fileName; }

	std::string getFilePath() const {return filePath;}
	void setFilePath(const std::string _filePath) { filePath= _filePath; }

	std::vector<Shape*> getShapes() const { return shapes; }
	Shape* getLastShape() const { return shapes.back();}

	Canvas* getCanvas() const { return canvas; }

	////////////////////////////

	void addShape(Shape* shape);
	void eraseShape(Shape* shape);
	void eraseAllShapes(Shape* shape);

	void reprint();
};

#endif // !FILE_H
