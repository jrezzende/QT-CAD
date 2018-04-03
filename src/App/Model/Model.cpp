#include "Model.h"

void Model::addFile(CADFile* file)
{
	files.push_back(file);
	file->connectClearRedo(std::bind(&Model::clearMemento, this));
}

void Model::deleteAllFiles()
{
	files.clear();
}

void Model::addShapeToMemento(CADShape* shape)
{
	mementoFile->mementoAddShape(*shape);
}