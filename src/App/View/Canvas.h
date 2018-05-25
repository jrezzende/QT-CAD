#pragma once
#ifndef INCLUDED_CANVAS_H
#define INCLUDED_CANVAS_H

#include "qwidget.h"
#include "qpainter.h"
#include "qpixmap.h"

class Rect;
class ViewMediator;
class CADShape;
class Handler;

class Canvas : public QWidget
{
	Q_OBJECT

	QPainter painter;
	QPixmap pixMap;

   ViewMediator* mediator;

	bool drawing;
   bool dragEvent;

   int currentDelta;

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
   void wheelEvent(QWheelEvent* event) override;
	void paintEvent(QPaintEvent* event) override; 

public:
	~Canvas()= default;
   Canvas(ViewMediator* _mediator, QWidget* parent);

   QPixmap& pixmap() { return pixMap; }

   void setDrawing(bool flag) { drawing = flag; }

	void callLine() const;
	void callBezier() const;
	void callArc() const;

   void toggleTracking();
   void clearMap();
   void endPainter();

	void drawCanvas(CADShape& shape);
	void drawPixmap(CADShape& shape);

	QPainterPath drawPath(CADShape& shape);
};

#endif //  INCLUDED_CANVAS_H