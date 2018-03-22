#pragma once
#ifndef SHAPEVISITOR_H
#define SHAPEVISITOR_H

class Line;
class Bezier;
class Arc;

class ShapeVisitor
{
public:
	virtual void visitLine(Line& l) = 0;
	virtual void visitBezier(Bezier& b) = 0;
	virtual void visitArc(Arc& a) = 0;
};
#endif // !SHAPEVISITOR_H