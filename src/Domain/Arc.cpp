#include "Arc.h"
#include <math.h>
#include <iostream>

Point& Arc::translatePoint(Point& p)
{
	 double translatedX= p.x - p1.x;
	 double translatedY= p.y - p1.y;

	 return Point(translatedX, translatedY);
}

Point& Arc::retranslatePoint(Point& p)
{
	double retranslatedX= p.x + p1.x;
	double retranslatedY= p.y + p1.y;

	return Point(retranslatedX, retranslatedY);
}

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

	Point p2Aux= translatePoint(p2);
	Point p3Aux= translatePoint(p3);

	//double dxp2 = p2Aux.x - p1.x; double dyp2 = p2Aux.y - p1.y;
	//double dxp3 = p3Aux.x - p1.x; double dyp3 = p3.y - p1.y;

	/*initialAngle = atan2(dyp2, dxp2); finalAngle = atan2(dyp3, dxp3);*/
	initialAngle = atan2(p2Aux.y, p2Aux.x); finalAngle = abs(atan2(p3Aux.y, p3Aux.x));

	/*radius = sqrt(dxp2 * dxp2 + dyp2 * dyp2);*/
	radius = sqrt(p2Aux.x * p2Aux.x + p2Aux.y * p2Aux.y);

	double arcAngleSize = radiansToDegrees(finalAngle - initialAngle);

	initialAngle = radiansToDegrees(initialAngle); finalAngle = radiansToDegrees(finalAngle);

	arcDivisions = calcArcDivisions(arcAngleSize);

	arcAngleSize = degreesToRadians(arcAngleSize);
	incrementAngle = arcAngleSize / arcDivisions;

	initialAngle = degreesToRadians(initialAngle); finalAngle = degreesToRadians(finalAngle);
	//std::cout << initialAngle << '-' << finalAngle << std::endl;
	for (auto i = initialAngle; i <= finalAngle; i += incrementAngle) {
		Point point;

		//point.x = p1.x + radius * cos(i);
		//point.y = p1.y + radius * sin(i);
		point.x = radius * cos(i);
		point.y = radius * sin(i);

		point= retranslatePoint(point);
		points.push_back(point);
	}

	return points;
}