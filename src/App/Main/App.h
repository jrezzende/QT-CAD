#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#include <memory>

class CADFileManager;
class CommandHandler;

class App
{
	std::unique_ptr<CADFileManager> fileManager;
	std::unique_ptr<CommandHandler> handler;

	static App* appInstance;

public:
	~App()= default;

	int start(int argc, char** argv);

public:
	static App& instance();
};

#endif //INCLUDED_APP_H