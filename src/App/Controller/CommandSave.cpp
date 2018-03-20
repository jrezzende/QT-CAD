#include "CommandSave.h"
#include "Model.h"
#include "MainWindow.h"
#include "ShapeType.h"

#include "Line.h"
#include "Bezier.h"
#include "Arc.h"

#include <fstream>

void CommandSave::persistLine(std::ofstream& os, Line& l)
{
	ShapeType shape= LINE;
	os.write((char*)&shape, sizeof(int));

	auto x= l.getFirstPoint().x;
	auto y= l.getFirstPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x= l.getSecondPoint().x;
	y= l.getSecondPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));
}

void CommandSave::persistBezier(std::ofstream& os, Bezier& b)
{
	ShapeType shape= BEZIER;
	os.write((char*)&shape, sizeof(int));

	auto x= b.getFirstPoint().x;
	auto y= b.getFirstPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x= b.getSecondPoint().x;
	y= b.getSecondPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x= b.getThirdPoint().x;
	y= b.getThirdPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));
}

void CommandSave::persistArc(std::ofstream& os, Arc& a)
{
	ShapeType shape= ARC;
	os.write((char*)&shape, sizeof(int));

	auto x= a.getFirstPoint().x;
	auto y= a.getFirstPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x= a.getSecondPoint().x;
	y= a.getSecondPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x= a.getThirdPoint().x;
	y= a.getThirdPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));
}

void CommandSave::execute(Model& m, MainWindow& w)
{
	if(m.getCurrentFile()->getStatus())
		return;


}
