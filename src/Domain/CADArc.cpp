#include "CADArc.h"

#include <cmath>

Point CADArc::translatePoint(Point& p)
{
	 const double translatedX= p.x - p1.x;
	 const double translatedY= p.y - p1.y;

	 return Point(translatedX, translatedY);
}

Point CADArc::retranslatePoint(Point& p)
{
	const double retranslatedX= p.x + p1.x;
	const double retranslatedY= p.y + p1.y;

	return Point(retranslatedX, retranslatedY);
}

int CADArc::calcArcDivisions(const double angleSize)
{
	int divisions= 0;

	if (angleSize <= 90)
		divisions = 50;
	else if (angleSize >= 90 && angleSize <= 180)
		divisions = 100;
	else if (angleSize >= 180 && angleSize <= 270)
		divisions = 150;
	else if (angleSize >= 270 && angleSize <= 360)
		divisions = 200;

	return divisions;
}

std::vector<Point> CADArc::coordinates()
{
	std::vector<Point> points;
	const Point p2Aux= translatePoint(p2);
	const Point p3Aux= translatePoint(p3);

	initialAngle = atan2(p2Aux.y, p2Aux.x); finalAngle = abs(atan2(p3Aux.y, p3Aux.x));

	radius = sqrt(p2Aux.x * p2Aux.x + p2Aux.y * p2Aux.y);

	double arcAngleSize = radiansToDegrees(finalAngle - initialAngle);

	initialAngle = radiansToDegrees(initialAngle); finalAngle = radiansToDegrees(finalAngle);

	arcDivisions = calcArcDivisions(arcAngleSize);

	arcAngleSize = degreesToRadians(arcAngleSize);
	incrementAngle = arcAngleSize / arcDivisions;

	initialAngle = degreesToRadians(initialAngle); finalAngle = degreesToRadians(finalAngle);

	for (auto i = initialAngle; i <= finalAngle; i += incrementAngle) {
		Point point;

		point.x = radius * cos(i);
		point.y = radius * sin(i);

		point= retranslatePoint(point);
		points.push_back(point);
	}

	return points;
}