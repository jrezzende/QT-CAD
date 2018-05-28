#include "PointMapper.h"

#include "CADFile.h"
#include "CADBezier.h"
#include "CADArc.h"
#include "TemplateIterator.h"

std::vector<CADShape*> PointMapper::transformShapes(CADFile& currentFile)
{
   std::vector<CADShape*> newShapes;
   newShapes.reserve(currentFile.shapesEnd() - currentFile.shapesBegin());

   for (auto shape : make_range(currentFile.shapesBegin(), currentFile.shapesEnd()))
      newShapes.push_back(shape->clone());

   for (auto shape : newShapes) {
      std::vector<Point> points;
      points.push_back(shape->firstPoint());
      points.push_back(shape->secondPoint());
      
      switch (shape->shapeType()) {
      case BEZIER: {
         auto bezier = dynamic_cast<CADBezier*>(shape);
         points.push_back(bezier->thirdPoint());
         break;
      }
      case ARC: {
         auto arc= dynamic_cast<CADArc*>(shape); 
         points.push_back(arc->thirdPoint());
         break;
      }
   }
      points= recalculatePointsInShape(points);

      shape->setFirstPoint(points.at(0));
      shape->setSecondPoint(points.at(1));

      switch (shape->shapeType()) {
      case BEZIER: {
         auto bezier= dynamic_cast<CADBezier*>(shape);
         bezier->setThirdPoint(points.at(2));
         break;
      }
      case ARC: {
         auto arc= dynamic_cast<CADArc*>(shape);
         arc->setThirdPoint(points.at(2));
         break;
      }
      }
   }

   return newShapes;
}

std::vector<Point> PointMapper::recalculatePointsInShape(std::vector<Point> points)
{
   std::vector<Point> recalculatedPoints;

   for (auto point : points)
      recalculatedPoints.push_back(Point(point + (upperLeftPoint)) * zFactor);
   
   return recalculatedPoints;
}

void PointMapper::recalculatePoint(Point& p)
{
   p= (p + (upperLeftPoint)) * zFactor;
}

void PointMapper::setZoomFactor()
{
   if (dFactor < 0) {
      if (zFactor > MINIMUM)
         zFactor--;
      return;
   }
   
   if (dFactor > 0) {
      if (zFactor < MAXIMUM)
         zFactor++;
      return;
   }

   return;
}
