#pragma once
#ifndef INCLUDED_POINTMAPPER_H
#define INCLUDED_POINTMAPPER_H

#include <vector>

#include "Point.h"
#include "CADFile.h"

class CADShape;

enum ZoomControl {
   MINIMUM = 1,
   MAXIMUM = 10,
   DEFAULT = MINIMUM
};

class PointMapper
{
   Point upperLeftPoint;

   int dFactor;
   int zFactor;

public:
   virtual ~PointMapper()= default;
   PointMapper() : upperLeftPoint(Point(0, 0)), zFactor(DEFAULT), dFactor(0) {}

   std::vector<CADShape*> transformShapes(CADFile& currentFile);
   std::vector<Point> recalculatePointsInShape(std::vector<Point> points);
   
   void recalculatePoint(Point& point);

   void reset() { dFactor= 0; zFactor= DEFAULT; }

   void setUpperLeftPoint(const Point& point) { upperLeftPoint= point; }
   void setDeltaFactor(const int factor) { dFactor = factor; setZoomFactor(); }
   void setZoomFactor();

   const int zoomFactor() { return zFactor; }
};

#endif // INCLUDED_POINTMAPPER_H
