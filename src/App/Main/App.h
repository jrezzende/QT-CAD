#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

class Model;
class MainWindow;
class CommandManager;

class App
{
	Model* model;
	MainWindow* window;
	CommandManager* manager;

	static App* instance;

	App() : model(nullptr), window(nullptr), manager(nullptr) {}

public:
	~App();

	Model& getModel() const { return *model; }
	MainWindow& getWindow() const { return *window; }
	CommandManager& getManager() const { return *manager; }

	int start(int argc, char** argv);

public:
	static App& getInstance();
};

#endif //  INCLUDED_APP_H
