#pragma once
#ifndef INCLUDED_RECT_H
#define INCLUDED_RECT_H

#include "Point.h"

class Rect
{
   int x1;
   int y1;
   int wd;
   int ht;

public:
   Rect() : x1(0), y1(0), wd(-1), ht(-1) {}
   Rect(const Point& topLeft, const Point& bottomRight) : 
      x1(topLeft.x), y1(topLeft.y), wd(bottomRight.x), ht(bottomRight.y) {}
   Rect(int _x1, int _y1, int _width, int _height) : x1(_x1), y1(_y1), wd(_width), ht(_height) {}

   bool isNull() { return (ht <= 0) && (wd <= 0); }

   Point& topLeft() { return Point(x1, y1); }
   Point& topRight() { return Point(wd, y1); }
   Point& bottomLeft() { return Point(x1, ht); }
   Point& bottomRight() { return Point(wd, ht); }
   Point& center() { return Point(((x1 + wd) / 2), (y1 + ht) / 2); }

   void setTopLeft(const Point& p) { x1 = p.x; y1 = p.y; }
   void setTopRight(const Point& p) { wd = p.x; y1 = p.y; }
   void setBottomLeft(const Point& p) { x1 = p.x; ht = p.y; }
   void setBottomRight(const Point& p) { wd = p.x; ht = p.y; }

   const int x() { return x1; }
   const int y() { return y1; }
   const int width() { return wd; }
   const int height() { return ht; }

   void translate(int dx, int dy) { this->x1 += dx; this->y1 += dy; this->wd += dx; this->ht += dy; }
   Rect& translated(int dx, int dy) { return Rect((Point(x1 + dx, y1 + dy)), (Point(wd + dx, ht + dy))); }

   inline bool operator==(const Rect& r) 
   { this->x1 == r.x1 && this->y1 == r.y1 && this->wd == r.wd && this->ht == r.ht; }
};

#endif // INCLUDED_RECT_H
