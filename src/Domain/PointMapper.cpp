#include "PointMapper.h"

#include "CADFile.h"
#include "CADBezier.h"
#include "CADArc.h"

std::vector<CADShape*> PointMapper::transformShapes(CADFile& currentFile, float zoom)
{
   if ((zoomFactor + zoom) >= 1)
      zoomFactor+= zoom;

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
   }
   return shapes;
}

std::vector<Point> PointMapper::recalculateShapePoints(std::vector<Point> points)
{
   for (auto& point : points)
      point= (point + upperLeftPoint) * zoomFactor;
   
   return points;
}

void PointMapper::recalculatePointToFile(Point& p)
{
   p= (p - (upperLeftPoint * zoomFactor)) * zoomFactor;
}

void PointMapper::recalculatePointToView(Point& p)
{
   p= (p + upperLeftPoint) * zoomFactor;
}

