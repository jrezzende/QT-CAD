#pragma once
#ifndef INCLUDED_POINTMAPPER_H
#define INCLUDED_POINTMAPPER_H

#include <vector>

#include "Point.h"
#include "CADFile.h"

class CADShape;

static const double constantFactor = 0.25;

class PointMapper
{
   Point upperLeftPoint;

   int wheelDelta;

public:
   virtual ~PointMapper()= default;
   PointMapper() : upperLeftPoint(Point(0, 0)), wheelDelta(0) {}

   std::vector<CADShape*> transformShapes(CADFile& currentFile, int zoom);
   std::vector<Point> recalculateShapePoints(std::vector<Point> points);
   
   void recalculatePointDeltaPositive(Point& point);
   void recalculatePointDeltaNegative(Point& point);

   void setDelta(const int deltaFactor) { wheelDelta= deltaFactor; }
   const int delta() { return wheelDelta; }

   //void setZoomFactor(const int factor) { zf= factor; }
   //const int zoomFactor() { return zf; }
};

#endif // INCLUDED_POINTMAPPER_H
