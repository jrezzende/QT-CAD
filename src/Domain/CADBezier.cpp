#include "CADBezier.h"

#include <cmath>

std::vector<Point> CADBezier::coordinates()
{
	std::vector<Point> points;

	for (float t= 0.0; t < 1.0; t+= 0.002f) {

		float xt= pow((1 - t), 2) * p1.x + (2 * t * (1 - t) * p3.x) + pow(t, 2)* p2.x;
		float yt= pow((1 - t), 2) * p1.y + (2 * t * (1 - t) * p3.y) + pow(t, 2)* p2.y;

		points.push_back(Point(int(xt), int(yt)));
	}

	return points;
}