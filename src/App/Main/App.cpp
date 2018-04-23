#include "qapplication.h"

#include "App.h"
#include "CADFileManager.h"
#include "Handler.h"

App* App::appInstance = nullptr;

App& App::instance()
{
   if (!appInstance)
      appInstance = new App;

   return *appInstance;
}

int App::start(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	fileManager= std::make_unique<CADFileManager>();
   handler= std::make_unique<Handler>(*fileManager);
   
	return app.exec();
}