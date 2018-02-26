#pragma once
#ifndef MODEL_H
#define MODEL_H

class Model
{
private:
	static Model* instance;
public:
	Model() {}
	~Model() {}

	Model* getInstance();
};

#endif // !MODEL_H
