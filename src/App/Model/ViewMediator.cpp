#include "ViewMediator.h"
#include "Handler.h"

void ViewMediator::sendMouseEvents(MouseEvent me, Point &p) const
{
   switch(me)
   {
   case PRESS:
      _manager->mousePressEvent(p);
      break;
   case MOVE:
      _manager->mouseMoveEvent(p);
      break;
   case RELEASE:
      _manager->mouseReleaseEvent(p);
      break;
   }
}

void ViewMediator::sendShapeEvents(ShapeType st) const
{
   switch(st)
   {
   case LINE:
      _manager->lineCommand();
      break;
   case BEZIER:
      _manager->bezierCommand();
      break;
   case ARC:
      _manager->arcCommand();
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
      _manager->newFileCmd();
      _manager->lineCommand();
      break;
   case LOAD:
      _manager->loadFileCmd();
      break;
   case SAVE:
      _manager->saveFileCmd();
      break;
   case UNDO:
      _manager->eraseLastShape();
      break;
   case REDO:
      _manager->redoShape();
      break;
   case CLEAR:
      _manager->clearShapes();
      break;
   case EXIT:
      _manager->exitFileCmd();
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
