#pragma once
#ifndef APP_H
#define APP_H

class MainWindow;
class Model;
class CommandManager;

class App
{
	Model* model;
	CommandManager* manager;
	MainWindow* window;

	static App* instance;
	App() : model(nullptr), manager(nullptr), window(nullptr) {}

public:
	~App();

	Model& getModel() const { return *model; }
	CommandManager& getManager() const { return *manager; }
	MainWindow& getWindow() const { return *window; }

	static App& getInstance();

	int start(int argc, char** argv);
};
#endif // !APP_H
