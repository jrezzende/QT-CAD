#include "CommandLoadFile.h"
#include "MainWindow.h"
#include "Canvas.h"
#include "File.h"

#include <fstream>

void CommandLoadFile::execute(Model& m, MainWindow& w)
{
	Canvas* canvas= w.createCanvas();
	std::string filePath= w.getOpenFileName();

	auto file= new File(filePath, canvas);

	std::ifstream is;
	is.open(filePath, std::ios::in | std::ios::binary);

	int type, p1x, p1y, p2x, p2y, p3x, p3y;

	if (is.is_open) {
		is.seekg(0);
	}
}