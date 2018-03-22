#pragma once
#ifndef SHAPEVISITORLOADFILE_H
#define SHAPEVISITORLOADFILE_H

#include "ShapeVisitor.h"

#include <fstream>

class ShapeVisitorLoadFile : public ShapeVisitor
{
	std::ifstream& is;
public:
	~ShapeVisitorLoadFile()= default;
	ShapeVisitorLoadFile(std::ifstream& _is) : is(_is) {};

	void visitLine(Line& l) override;
	void visitBezier(Bezier& b) override;
	void visitArc(Arc& a) override;
};

#endif // !SHAPEVISITORLOADFILE_H
