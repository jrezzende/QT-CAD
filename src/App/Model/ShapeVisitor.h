#pragma once
#ifndef INCLUDED_SHAPEVISITOR_H
#define INCLUDED_SHAPEVISITOR_H

class CADLine;
class CADBezier;
class CADArc;

class ShapeVisitor
{
public:
	virtual void visitLine(CADLine& l) = 0;
	virtual void visitBezier(CADBezier& b) = 0;
	virtual void visitArc(CADArc& a) = 0;
};

#endif //  INCLUDED_SHAPEVISITOR_H