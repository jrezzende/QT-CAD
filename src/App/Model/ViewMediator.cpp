#include "ViewMediator.h"
#include "Handler.h"

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
      handler->lineCommand();
      break;
   case BEZIER:
      handler->bezierCommand();
      break;
   case ARC:
      handler->arcCommand();
      break;
   case UNDEFINED:
      return;
   }
}

void ViewMediator::sendMessage(std::string& s) const
{
   _window.statusBar()->showMessage(QString::fromStdString(s), 1000);
}

void ViewMediator::sendCommand(WindowActions wa) const
{
   switch(wa)
   {
   case NEW:
      handler->newFileCmd();
      handler->lineCommand();
      break;
   case LOAD:
      handler->loadFileCmd();
      break;
   case SAVE:
      handler->saveFileCmd();
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
      handler->exitFileCmd();
      break;
   }
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
