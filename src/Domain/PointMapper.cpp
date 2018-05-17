#include "PointMapper.h"

#include "CADFile.h"
#include "CADBezier.h"
#include "CADArc.h"

std::vector<CADShape*> PointMapper::transformShapes(CADFile& currentFile, float zoom)
{
   std::vector<CADShape*> shapes= currentFile.shapesVector();

   for (auto shape : shapes) {
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
      points= recalculateShapePoints(points);

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
   return shapes;
}

std::vector<Point> PointMapper::recalculateShapePoints(std::vector<Point> points)
{
   std::vector<Point> recalculatedPoints;

   for (auto point : points)
      recalculatedPoints.push_back(Point((point + upperLeftPoint) * zoomFactor));
   
   return recalculatedPoints;
}

void PointMapper::recalculatePointToFile(Point& p)
{
   p= (p - (upperLeftPoint * zoomFactor)) / zoomFactor;
}

void PointMapper::recalculatePointToView(Point& p)
{
   p= (p + upperLeftPoint) * zoomFactor;
}