#include "Model.h"

void Model::addFile(File * file)
{
	files.push_back(file);
	file->connectClearRedo(std::bind(&Model::clearMemento, this));
}

void Model::deleteAllFiles()
{
	files.clear();
}

void Model::addShapeToMemento(Shape* shape)
{
	mementoFile->mementoAddShape(shape);
}