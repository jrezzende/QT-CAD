#include "Model.h"

Model * Model::getInstance()
{
	if(instance)
		delete instance;

	instance= new Model();

	return instance;
}
