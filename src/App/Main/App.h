#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class CADFileManager;
class Manager;

class App
{
	CADFileManager* fileManager;
	Manager* manager;

	static App* appInstance;

	App() : fileManager(nullptr), manager(nullptr) {}

public:
	~App();

	int start(int argc, char** argv);

public:
	static App& instance();
};

#endif //INCLUDED_APP_H