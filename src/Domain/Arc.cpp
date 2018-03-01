#include "Arc.h"
#include <math.h>
#include <iostream>

int Arc::calcArcDivisions(double angleArcSize)
{
	int divisions;

	if (angleArcSize <= 90)
		divisions = 50;
	else if (angleArcSize >= 90 && angleArcSize <= 180)
		divisions = 100;
	else if (angleArcSize >= 180 && angleArcSize <= 270)
		divisions = 150;
	else if (angleArcSize >= 270 && angleArcSize <= 360)
		divisions = 200;

	return divisions;
}

std::vector<Point> Arc::getCoordinates()
{
	std::vector<Point> points;

	double dxp2 = p2.x - p1.x; double dyp2 = p2.y - p1.y; // dxy p2
	double dxp3 = p3.x - p1.x; double dyp3 = p3.y - p1.y; // dxy p3

	initialAngle = atan2(dyp2, dxp2); finalAngle = atan2(dyp3, dxp3);

	radius = sqrt(dxp2 * dxp2 + dyp2 * dyp2);

	double arcAngleSize = radiansToDegrees(finalAngle - initialAngle);

	initialAngle = radiansToDegrees(initialAngle); finalAngle = radiansToDegrees(finalAngle);

	arcDivisions = calcArcDivisions(arcAngleSize);

	arcAngleSize = degreesToRadians(arcAngleSize);
	incrementAngle = arcAngleSize / arcDivisions;

	initialAngle = degreesToRadians(initialAngle); finalAngle = degreesToRadians(finalAngle);

	for (auto i = initialAngle; i <= finalAngle; i += incrementAngle) {
		Point point;

		point.x = p1.x + radius * cos(i);
		point.y = p1.y + radius * sin(i);

		points.push_back(point);
	}
	return points;
}