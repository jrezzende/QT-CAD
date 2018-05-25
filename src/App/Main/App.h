#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class CADFileManager;
class CommandHandler;

class App
{
	CADFileManager* fileManager;
	CommandHandler* handler;

public:
	~App()= default;
   App()= default;

	int start(int argc, char** argv);
};

#endif //INCLUDED_APP_H