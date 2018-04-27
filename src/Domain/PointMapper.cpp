#include "PointMapper.h"

PointMapper::PointMapper(Point & p1, Point & p2, int height, int width) :
   worldP1(p1), worldP2(p2), deviceHeight(height), deviceWidth(width)
{
   calcDeltas();
   setDeviceSize(deviceHeight, deviceWidth);
}

Point& PointMapper::mapWorldToDevice(Point& devicePoint)
{
   return Point(devicePoint.x, devicePoint.y);
}

Point& PointMapper::mapDeviceToWorld(Point& worldPoint)
{
   return Point(worldPoint.x, worldPoint.y);
}

void PointMapper::calcDeltas()
{
   return;
}

void PointMapper::adjustProportions()
{
   return;
}

void PointMapper::zoom()
{
   return;
}

void PointMapper::translateWorldPoints()
{
   return;
}

void PointMapper::setWorldSize()
{
   return;
}

void PointMapper::setDeviceSize(int height, int width)
{
   if(height <= 0 || width <= 0)
      return;

   deviceHeight= height;
   deviceWidth= width;

   adjustProportions();
}
