#include "Model.h"

Model * Model::getInstance()
{
	if(instance)
		delete instance;

	instance= new Model();

	return instance;
}

void Model::deleteAllFiles()
{
	for(int i= 0; i < files.size(); i++)
		delete files[i];

	files.clear();
}
