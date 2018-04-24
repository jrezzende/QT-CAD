#pragma once
#ifndef INCLUDED_SHAPEVISITORSAVEFILE_H
#define INCLUDED_SHAPEVISITORSAVEFILE_H

#include "ShapeVisitor.h"

#include <fstream>

class ShapeVisitorSaveFile : public ShapeVisitor
{
	std::ostream& os;

public:
	virtual ~ShapeVisitorSaveFile()= default;

	explicit ShapeVisitorSaveFile(std::ostream& _os) : os(_os) {};

	void visitLine(CADLine& l) override;
	void visitBezier(CADBezier& b) override;
	void visitArc(CADArc& a) override;
};

#endif //  INCLUDED_SHAPEVISITORSAVEFILE_H