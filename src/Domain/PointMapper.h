#pragma once
#ifndef INCLUDED_POINTMAPER_H
#define INCLUDED_POINTMAPER_H

#include <vector>

#include "Point.h"
#include "CADFile.h"

class CADShape;

class PointMapper
{
   float zoomFactor;
   Point upperLeftPoint;

public:
   virtual ~PointMapper()= default;
   PointMapper() : zoomFactor(1.0), upperLeftPoint(Point(0, 0)) {}

   std::vector<CADShape*> transformShapes(CADFile& currentFile, float zoom);
   std::vector<Point> recalculateShapePoints(std::vector<Point> points);
   
   void recalculatePointToFile(Point& point);
   void recalculatePointToView(Point& point);

   void setZoomFactor(float zf) { zoomFactor= zf; }
};

#endif // INCLUDED_POINTMAPER_H
