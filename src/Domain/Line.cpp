#include "Line.h"

std::vector<Point> Line::getCoordinates()
{
	std::vector<Point> points;
	points.push_back(p1);

	int x= p1.x;
	int y= p1.y;

	int verticalDistance= p2.y - p1.y;
	int horizontalDistance= p2.x - p1.x;
	int verticalStep, horizontalStep;

	verticalDistance < 0 ? verticalStep= -1 : verticalStep= 1;
	verticalDistance *= verticalStep;

	horizontalDistance < 0 ? horizontalStep= -1 : horizontalStep= 1;
	horizontalDistance *= horizontalStep;

	if (horizontalDistance > verticalDistance) {
		for (int fraction = verticalDistance - horizontalDistance; x != p2.x; points.push_back(Point(x, y))) {
			if (fraction >= 0) {
				y+= verticalStep;
				fraction-= horizontalDistance;
			}
			x+= horizontalStep;
			fraction+= verticalDistance;
		}
	}
	else {
		for (int fraction = horizontalDistance - verticalDistance; y != p2.y; points.push_back(Point(x, y))) {
			if (fraction >= 0) {
				x+= horizontalStep;
				fraction-= verticalDistance;
			}
			y+= verticalStep;
			fraction+= horizontalDistance;
		}
	}

	return points;
}