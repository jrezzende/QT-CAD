#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class CADFileManager;
class Manager;

class App
{
	CADFileManager* fileManager;
	Manager* manager;

	static App* instance;

	App() : fileManager(nullptr), manager(nullptr) {}

public:
	~App();

	CADFileManager& getFileManager() const { return *fileManager; }
	Manager& getManager() const { return *manager; }

	int start(int argc, char** argv);

public:
	static App& getInstance();
};

#endif //  INCLUDED_APP_H
