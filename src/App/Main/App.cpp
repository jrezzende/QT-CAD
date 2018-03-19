#include "App.h"
#include "Model.h"
#include "MainWindow.h"
#include "CommandManager.h"
#include "Canvas.h"

#include "qapplication.h"

App::~App()
{
	delete manager;
	delete model;
	delete window;
}

int App::start(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	model= new Model;
	window= new MainWindow;
	manager= new CommandManager(*model, *window);

	window->setManager(*manager);

	auto file = new File("Untitled", "", window->createCanvas());
		
	model->newFile(file);
	model->setCurrentFile(file);
	window->setCentralWidget(file->getCanvas());

	return app.exec();
}

App* App::instance= nullptr;

App& App::getInstance()
{
	if(!instance)
		instance= new App;

	return *instance;
}
