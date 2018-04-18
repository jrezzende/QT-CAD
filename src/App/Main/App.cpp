#include "qapplication.h"

#include "App.h"
#include "CADFileManager.h"
#include "Manager.h"

App* App::appInstance = nullptr;

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

App& App::instance()
{
	if(!appInstance)
      appInstance = new App;

	return *appInstance;
}