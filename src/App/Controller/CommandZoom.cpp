#include "CommandZoom.h"
#include "ViewMediator.h"
#include "CADFileManager.h"
#include "Canvas.h"
#include "Rect.h"
#include "Point.h"

void CommandZoom::execute(CADFileManager& fmanager, ViewMediator& vmediator)
{
   int x= vmediator.canvas().geometry().x();
   int y= vmediator.canvas().geometry().y();
   int width= vmediator.canvas().geometry().width();
   int height= vmediator.canvas().geometry().height();

   Rect* viewRect= new Rect(x, y, width, height);

   auto dX= viewRect->width() * (1 - 1 / zoomFactor);
   auto dY= viewRect->height() * (1 - 1 / zoomFactor);

   auto posX= (focus.x - viewRect->x()) / viewRect->width();
   auto posY= (focus.y - viewRect->y()) / viewRect->height();

   auto distanceLeft= posX * dX;
   auto distanceUp= posY * dY;
}