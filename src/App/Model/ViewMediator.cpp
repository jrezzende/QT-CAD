#include "ViewMediator.h"
#include "Handler.h"
#include "Canvas.h"

void ViewMediator::sendMouseEvents(MouseEvent me, Point& p) const
{
   switch(me)
   {
   case PRESS:
      handler->mousePressEvent(p);
      break;
   case MOVE:
      handler->mouseMoveEvent(p);
      break;
   case RELEASE:
      handler->mouseReleaseEvent(p);
      break;
   }
}

void ViewMediator::sendShapeEvents(const ShapeType st) const
{
   switch(st)
   {
   case LINE:
      handler->createLineCommand();
      break;
   case BEZIER:
      handler->createBezierCommand();
      break;
   case ARC:
      handler->createArcCommand();
      break;
   case UNDEFINED:
      return;
   }
}

void ViewMediator::sendMessage(std::string& s) const
{
   _window.statusBar()->showMessage(QString::fromStdString(s), 1000);
}

void ViewMediator::sendCommand(const WindowActions wa) const
{
   switch(wa)
   {
   case NEW:
      handler->createNewFileCmd();
      handler->createLineCommand();
      break;
   case LOAD:
      handler->createLoadFileCmd();
      break;
   case SAVE:
      handler->createSaveFileCmd();
      break;
   case UNDO:
      handler->eraseLastShape();
      break;
   case REDO:
      handler->redoShape();
      break;
   case CLEAR:
      handler->clearShapes();
      break;
   case EXIT:
      handler->createExitFileCmd();
      break;
   }
}

void ViewMediator::zoomFocus(Point& p) const
{
   handler->createZoomCmd(p, canvas().zoomFactor());
}

std::string ViewMediator::fileLabel(WindowActions wa)
{
   switch(wa)
   {
   case NEW:
      return std::string(_window.newFileName());
   case LOAD:
      return std::string(_window.openFileName());
   case SAVE:
      return std::string(_window.saveFileName());
   default:
      return "";
   }
}
