#include "PointMapper.h"

PointMapper::PointMapper(Point & p1, Point & p2, int height, int width) :
   worldP1(p1), worldP2(p2), deviceHeight(height), deviceWidth(width)
{
   calcDeltas();
   setDeviceSize(deviceHeight, deviceWidth);
}

Point & PointMapper::mapWorldToDevice(Point& devicePoint)
{
   // TODO: insert return statement here
}

Point & PointMapper::mapDeviceToWorld(Point& worldPoint)
{
   // TODO: insert return statement here
}

void PointMapper::calcDeltas()
{
}

void PointMapper::adjustProportions()
{
}

void PointMapper::zoom()
{
}

void PointMapper::translateWorldPoints()
{

}

void PointMapper::setWorldSize()
{
   /////////
}

void PointMapper::setDeviceSize(int height, int width)
{
   if(height <= 0 || width <= 0)
      return;

   deviceHeight= height;
   deviceWidth= width;

   adjustProportions();
}
