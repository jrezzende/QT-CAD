#include "CommandNewFile.h"
#include "MainWindow.h"
#include "Model.h"
#include "File.h"
#include "Canvas.h"

#include <iostream>

void CommandNewFile::execute(Model& m, MainWindow& w)
{
	std::string fileName= "Untitled " /*+ m.getFileQuantity()*/;

	File* file= new File(fileName, w.createCanvas());	

	m.setCurrentFile(file);
	m.newFile(file);

	w.setCentralWidget(file->getCanvas());

	// std::cout << "new file" << std::endl; #test purposes only
}
