#include "ShapeVisitorSaveFile.h"
#include "ShapeType.h"
#include "CADLine.h"
#include "CADBezier.h"
#include "CADArc.h"

void ShapeVisitorSaveFile::visitLine(CADLine& l)
{
	ShapeType shape = LINE;
	os.write((char*)&shape, sizeof(int));

	auto x = l.firstPoint().x;
	auto y = l.firstPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x = l.secondPoint().x;
	y = l.secondPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));
}

void ShapeVisitorSaveFile::visitBezier(CADBezier & b)
{
	ShapeType shape = BEZIER;
	os.write((char*)&shape, sizeof(int));

	auto x = b.firstPoint().x;
	auto y = b.firstPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x = b.secondPoint().x;
	y = b.secondPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x = b.thirdPoint().x;
	y = b.thirdPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));
}

void ShapeVisitorSaveFile::visitArc(CADArc & a)
{
	ShapeType shape = ARC;
	os.write((char*)&shape, sizeof(int));

	auto x = a.firstPoint().x;
	auto y = a.firstPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x = a.secondPoint().x;
	y = a.secondPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));

	x = a.thirdPoint().x;
	y = a.thirdPoint().y;
	os.write((char*)&x, sizeof(double));
	os.write((char*)&y, sizeof(double));
}
