#pragma once
#ifndef INCLUDED_SIZE_H
#define INCLUDED_SIZE_H

class Size
{
   int wd;
   int ht;
public:
   Size() : wd(0), ht() {}
   Size(int width, int height) : wd(width), ht(height) {}

   bool isNull() { return wd <= 0 && ht <= 0; }

   int width() { return wd; }
   int height() { return ht; }

   void setWidth(int width) { wd= width; }
   void setHeight(int height) { ht = height; }
};

#endif // INCLUDED_SIZE_H
