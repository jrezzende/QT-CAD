#ifndef INCLUDED_POINTMAPER_H
#define INCLUDED_POINTMAPER_H

#include "Point.h"

class PointMapper
{
   Point worldP1;
   Point worldP2;

   int deviceHeight;
   int deviceWidth;

   double deltaY;
   double deltaX;

   double worldDeltaY;
   double worldDeltaX;

   void calcDeltas();
   void adjustProportions();

public:
   virtual ~PointMapper()= default;
   PointMapper(Point& p1, Point& p2, int height, int width);

   Point& mapWorldToDevice();
   Point& mapDeviceToWorld();
   
   void zoom();
   void translateWorldPoints();

   void setWorldSize();
   void setDeviceSize(int height, int width);
};

#endif // INCLUDED_POINTMAPER_H
