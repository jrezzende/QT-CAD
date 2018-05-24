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
	std::string name;
	std::string path;

	std::vector<CADShape*> shapes;

	Status fileStatus;
	Canvas* drawArea;

	std::function<void()> clearRedo;

public:
	~CADFile()= default;
	explicit CADFile(const std::string _fileName) : name(_fileName), fileStatus(NOTSAVED), drawArea(nullptr) {}
	CADFile(const std::string _fileName, Canvas* _canvas) : name(_fileName), fileStatus(NOTSAVED), drawArea(_canvas) {}
	CADFile(
      const std::string _fileName, const std::string _filePath, Canvas* _canvas
   ) : name(_fileName), path(_filePath), fileStatus(NOTSAVED), drawArea(_canvas) {}

	void setStatus(Status _status) { fileStatus = _status; }
	bool status() const { return fileStatus; }
	
	void setFileName(const std::string& _fileName) { name = _fileName; }
	std::string fileName() const { return name; }

	void setFilePath(const std::string& _filePath) { path = _filePath; }
	std::string filePath() const {return path;}
	
   std::vector<CADShape*>shapesVector() { return shapes; }
   std::vector<CADShape*>::const_iterator shapesBegin() const { return shapes.begin(); }
   std::vector<CADShape*>::const_iterator shapesEnd() const { return shapes.end(); }

	CADShape& lastShape() const { return *shapes.back();}
	
	void popShape() { shapes.pop_back(); }

	Canvas* canvas() const { return drawArea; }
   void setCanvas(Canvas& _canvas) { drawArea = &_canvas; }

	void connectClearRedo(std::function<void()> func) { clearRedo = func; }

	////////////////////////////

	void addShape(CADShape& shape);
	void addFromRedo(CADShape& shape);
	void eraseShape(CADShape& shape);
	void eraseLastShape();
	void eraseAllShapes();
	void reprint();
};

#endif //  INCLUDED_CADFile_H