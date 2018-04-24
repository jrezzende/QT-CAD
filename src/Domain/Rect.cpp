#include "Rect.h"
#include "Point.h"

bool Rect::isNull()
{
   return (height <= 0) && (width <= 0);
}

Point& Rect::topLeft()
{
   return Point(x1, y1);
}

Point& Rect::topRight()
{
   return Point(width, y1);
}

Point& Rect::bottomLeft()
{
   return Point(x1, height);
}

Point& Rect::bottomRight()
{
   return Point(width, height);
}

Point& Rect::center()
{
   return Point(((x1 + width) / 2), ( y1 + height) / 2);
}

void Rect::setTopLeft(const Point& p)
{
  x1= p.x; y1= p.y;
}

void Rect::setTopRight(const Point& p)
{
   width= p.x; y1= p.y;
}

void Rect::setBottomLeft(const Point& p)
{
   x1= p.x; height= p.y;
}

void Rect::setBottomRight(const Point& p)
{
   width= p.x; height= p.y;
}
