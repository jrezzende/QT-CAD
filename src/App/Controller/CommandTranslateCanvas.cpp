#include "Command.h"
#include "CommandTranslateCanvas.h"
#include "CommandHandler.h"

void CommandTranslateCanvas::mousePressEvent(const Point & point)
{
   translationPoint = point;
}

void CommandTranslateCanvas::mouseMoveEvent(const Point & point)
{
   gap= translationPoint - point;
   viewMediator.handler().pointMapper().setUpperLeftPoint(gap);

   auto shapes= viewMediator.handler().pointMapper().transformShapes(fileManager.current());
   viewMediator.canvas().clearMap();

   for (auto shape : shapes) {
      viewMediator.canvas().drawCanvas(*shape);
   }

   viewMediator.handler().pointMapper().setUpperLeftPoint(Point(0, 0));
}