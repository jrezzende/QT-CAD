#include "ViewMediator.h"
#include "Manager.h"

void ViewMediator::sendMouseEvents(MouseEvent me, Point & p) const
{
   switch(me)
   {
   case PRESS:
      manager->mousePressEvent(p);
      break;
   case MOVE:
      manager->mouseMoveEvent(p);
      break;
   case RELEASE:
      manager->mouseReleaseEvent(p);
      break;
   }
}

void ViewMediator::sendShapeEvents(ShapeType st) const
{
   switch(st)
   {
   case LINE:
      manager->lineCommand();
      break;
   case BEZIER:
      manager->bezierCommand();
      break;
   case ARC:
      manager->arcCommand();
      break;
   case UNDEFINED:
      return;
   }
}

void ViewMediator::sendMessage(std::string& s) const
{
   window.getStatusBar()->showMessage(QString::fromStdString(s), 1000);
}

void ViewMediator::sendCommand(WindowActions wa) const
{
   switch(wa)
   {
   case NEW:
      manager->newFileCmd();
      manager->lineCommand();
      break;
   case LOAD:
      manager->loadFileCmd();
      break;
   case SAVE:
      manager->saveFileCmd();
      break;
   case UNDO:
      manager->eraseLastShape();
      break;
   case REDO:
      manager->redoShape();
      break;
   case CLEAR:
      manager->clearShapes();
      break;
   case EXIT:
      manager->exitFileCmd();
      break;
   }
}

std::string ViewMediator::retrieveFileLabel(WindowActions wa)
{
   switch(wa)
   {
   case NEW:
      return std::string(window.getNewFileName());
   case LOAD:
      return std::string(window.getOpenFileName());
   case SAVE:
      return std::string(window.getSaveFileName());
   default:
      return "";
   }
}
