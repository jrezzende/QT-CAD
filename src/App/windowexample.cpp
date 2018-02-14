#include "MainWindow.h"
#include <qevent.h>
#include <qline.h>
#include <qmenubar.h>
#include <qaction.h>
#include <qpainter.h>

void MainWindow::mousePressEvent(QMouseEvent * event)
{
	QLine* line = new QLine(QPoint(0, 0), QPoint(0, 0));
	line->setP1(event->pos());
}

void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
	lines.back()->setP2(event->pos());
	update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent * event)
{
	
}

void MainWindow::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);

	for (auto line : lines)
		painter.drawLine(*line);
}

MainWindow::MainWindow()
{
	setMinimumSize(800, 600);

	QAction* line = new QAction("Line");

	menuBar()->addAction(line);

	QWidget* widget = new QWidget(this);
	setCentralWidget(widget);
	show();
}
