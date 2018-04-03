#pragma once
#ifndef INCLUDED_CANVAS_H
#define INCLUDED_CANVAS_H

#include "qwidget.h"
#include "qpainter.h"
#include "qpixmap.h"
#include "qtransform.h"

class CADShape;
class CommandManager;

class Canvas : public QWidget
{
	Q_OBJECT

	QPainter painter;
	QPixmap pixmap;

	CommandManager* manager;

	bool drawing;

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void paintEvent(QPaintEvent* event) override; 

public:
	~Canvas() {}
	Canvas(CommandManager* manager, QWidget* parent);

	QPixmap& getPixmap() { return pixmap;}

	void setDrawing(bool flag) { drawing = flag; }

public slots:
	void clearMap();
	void dumpShapes();
	void dumpLastShape();
	void toggleTracking();
	void endPainter();

public:
	void saveCurrentFile();

	void callLine();
	void callBezier();
	void callArc();

	void drawCanvas(CADShape& shape);
	void drawMap(CADShape& shape);

	QPainterPath getDrawPath(CADShape& shape);
};

#endif //  INCLUDED_CANVAS_H