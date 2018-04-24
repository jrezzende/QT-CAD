#ifndef INCLUDED_RECT_H
#define INCLUDED_RECT_H

class Point;

class Rect
{
   int x1;
   int y1;
   int width;
   int height;

public:
   Rect() : x1(0), y1(0), width(-1), height(-1) {}
   Rect(const Point& topLeft, const Point& bottomRight) : 
      x1(topLeft.x), y1(topLeft.y), width(bottomRight.x), height(bottomRight.y) {}
   Rect(int _x1, int _y1, int _width, int _height) : x1(_x1), y1(_y1), width(_width), height(_height) {}

   bool isNull();

   Point& topLeft();
   Point& topRight();
   Point& bottomLeft();
   Point& bottomRight();
   Point& center();

   void setTopLeft(const Point& p);
   void setTopRight(const Point& p);
   void setBottomLeft(const Point& p);
   void setBottomRight(const Point& p);
};

#endif // INCLUDED_RECT_H
