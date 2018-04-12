#include "qapplication.h"

#include "App.h"
#include "CADFileManager.h"
#include "Manager.h"
#include "ViewMediator.h"

App* App::instance= nullptr;

App::~App()
{
	delete fileManager;
   delete manager;
}

int App::start(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	fileManager= new CADFileManager;
   manager= new Manager(*fileManager);
   
	return app.exec();
}

App& App::getInstance()
{
	if(!instance)
		instance= new App;

	return *instance;
}