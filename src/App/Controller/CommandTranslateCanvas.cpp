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
   viewMediator.manager().pointMapper().setUpperLeftPoint(gap);

   auto shapes= viewMediator.manager().pointMapper().transformShapes(fileManager.currentFile());
   viewMediator.canvas().clearMap();

   for (auto shape : shapes) {
      viewMediator.canvas().drawCanvas(*shape);
   }

   viewMediator.manager().pointMapper().setUpperLeftPoint(Point(0, 0));
}