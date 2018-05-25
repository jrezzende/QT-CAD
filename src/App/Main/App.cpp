#include "qapplication.h"

#include "App.h"
#include "CADFileManager.h"
#include "CommandHandler.h"

int App::start(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	fileManager= new CADFileManager();
   handler= new CommandHandler(*fileManager);
   
	return app.exec();
}