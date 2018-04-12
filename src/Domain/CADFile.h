#pragma once
#ifndef INCLUDED_CADFile_H
#define INCLUDED_CADFile_H

#include <functional>

#include "CADShape.h"

class Canvas;

enum Status
{
	NOTSAVED,
	SAVED
};

class CADFile
{
	std::string fileName;
	std::string filePath;

	std::vector<CADShape*> shapes;

	Status status;
	Canvas* canvas;

	std::function<void()> clearRedo;

public:
	~CADFile()= default;
	CADFile(const std::string _fileName) : fileName(_fileName), status(NOTSAVED), canvas(nullptr) {}
	CADFile(const std::string _fileName, Canvas* _canvas) : fileName(_fileName), status(NOTSAVED), canvas(_canvas) {}
	CADFile(
      const std::string _fileName, const std::string _filePath, Canvas* _canvas
   ) : fileName(_fileName), filePath(_filePath), status(NOTSAVED), canvas(_canvas) {}

	void setStatus(Status _status) { status = _status; }
	bool getStatus() const { return status; } 
	
	void setFileName(const std::string& _fileName) { fileName = _fileName; }
	std::string getFileName() const { return fileName; }

	void setFilePath(const std::string& _filePath) { filePath = _filePath; }
	std::string getFilePath() const {return filePath;}
	
	std::vector<CADShape*> getShapes() const { return shapes; }
	CADShape* getLastShape() const { return shapes.back();}
	
	void popShape() { shapes.pop_back(); }

	Canvas* getCanvas() const { return canvas; }
   void setCanvas(Canvas& _canvas) { canvas= &_canvas; }

	void connectClearRedo(std::function<void()> func) { clearRedo = func; }

	////////////////////////////

	void addShape(CADShape& shape);
	void addFromRedo(CADShape& shape);
	void mementoAddShape(CADShape& shape);
	void eraseShape(CADShape& shape);
	void eraseLastShape();
	void eraseAllShapes();
	void reprint();
};

#endif //  INCLUDED_CADFile_H