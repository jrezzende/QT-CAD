#include "App.h"
#include "Model.h"
#include "MainWindow.h"
#include "CommandManager.h"
#include "Canvas.h"

#include "qapplication.h"

App* App::instance= nullptr;

App::~App()
{
	delete model;
	delete manager;
	delete window;
}

int App::start(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	model= new Model;
	window= new MainWindow;
	manager= new CommandManager(*model, *window);

	window->setManager(*manager);

	const auto file= new CADFile("Untitled", window->createCanvas());
	const auto mementoFile= new CADFile("memento", file->getCanvas());
		
	model->addFile(file);
	model->setCurrentFile(file);
	model->addFile(mementoFile);
	model->setMementoFile(mementoFile);
	model->setMementoFlag(false);

	window->setCentralWidget(file->getCanvas());

	return app.exec();
}

App& App::getInstance()
{
	if(!instance)
		instance= new App;

	return *instance;
}
