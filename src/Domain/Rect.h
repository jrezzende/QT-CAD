#pragma once
#ifndef INCLUDED_RECT_H
#define INCLUDED_RECT_H

#include "Point.h"

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

   bool isNull() { return (height <= 0) && (width <= 0); }

   Point& topLeft() { return Point(x1, y1); }
   Point& topRight() { return Point(width, y1); }
   Point& bottomLeft() { return Point(x1, height); }
   Point& bottomRight() { return Point(width, height); }
   Point& center() { return Point(((x1 + width) / 2), (y1 + height) / 2); }

   void setTopLeft(const Point& p) { x1 = p.x; y1 = p.y; }
   void setTopRight(const Point& p) { width = p.x; y1 = p.y; }
   void setBottomLeft(const Point& p) { x1 = p.x; height = p.y; }
   void setBottomRight(const Point& p) { width = p.x; height = p.y; }

   void translate(int dx, int dy) { this->x1 += dx; this->y1 += dy; this->width += dx; this->height += dy; }
   Rect& translated(int dx, int dy) { return Rect((Point(x1 + dx, y1 + dy)), (Point(width + dx, height + dy))); }

   inline bool operator==(const Rect& r) 
   { this->x1 == r.x1 && this->y1 == r.y1 && this->width == r.width && this->height == r.height; }
};

#endif // INCLUDED_RECT_H
