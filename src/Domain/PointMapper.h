#pragma once
#ifndef INCLUDED_POINTMAPER_H
#define INCLUDED_POINTMAPER_H

#include <vector>

#include "Point.h"

class CADShape;
class CADFile;

class PointMapper
{
   float zoomFactor;
   Point upperLeftPoint;

public:
   virtual ~PointMapper()= default;
   PointMapper() : zoomFactor(1), upperLeftPoint(Point(0, 0)) {}

   std::vector<CADShape*> transformShapes(CADFile& currentFile, float zoom);
   std::vector<Point&> recalculateShapePoints(CADShape& shape);
   
   void recalculatePointsFromView(std::vector<Point&> points);
   void recalculatePointsFromFile(std::vector<Point&> points);
};

#endif // INCLUDED_POINTMAPER_H
