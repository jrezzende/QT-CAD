#pragma once
#ifndef SHAPEVISITORSAVEFILE_H
#define SHAPEVISITORSAVEFILE_H

#include "ShapeVisitor.h"

#include <fstream>

class ShapeVisitorSaveFile : public ShapeVisitor
{
	std::ostream& os;
public:
	~ShapeVisitorSaveFile()= default;
	ShapeVisitorSaveFile(std::ostream& _os) : os(_os) {};

	void visitLine(Line& l) override;
	void visitBezier(Bezier& b) override;
	void visitArc(Arc& a) override;
};

#endif // !SHAPEVISITORSAVEFILE_H
