#include <sstream>

#include "ViewMediator.h"
#include "CommandHandler.h"
#include "Canvas.h"
#include "PointMapper.h"

void ViewMediator::sendMouseEvents(MouseEvent me, Point& p) const
{
   switch(me)
   {
   case PRESS:
      handler->mousePressEvent(p);
      sendMouseMessages(PRESS, p);
      break;
   case MOVE:
      handler->mouseMoveEvent(p);
      sendMouseMessages(MOVE, p);
      break;
   case RELEASE:
      handler->mouseReleaseEvent(p);
      sendMouseMessages(RELEASE, p);
      break;
   case WHEEL:
      sendMouseMessages(WHEEL, p);
      break;
   case TRACKING:
      sendMouseMessages(TRACKING, p);
      break;
   case RIGHTCLICK:
      handler->rightClickEvent(p);
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

void ViewMediator::sendMouseMessages(const MouseEvent me, const Point& p) const
{
   std::ostringstream aux;

   switch (me)
   {
   case PRESS:
      aux << "Mouse press event detected: X: " << p.x << " Y: " << p.y;
      break;
   case MOVE:
      aux << "Mouse move event detected: X: " << p.x << " Y: " << p.y;
      break;
   case RELEASE:
      aux << "Mouse release event detected: X: " << p.x << " Y: " << p.y;
      break;
   case WHEEL:
      aux << "Mouse wheel event detected: X: " << p.x << " Y: " << p.y;
      break;
   case TRACKING:
      aux << "Mouse tracking mode on. Hover position: X: " << p.x << " Y: " << p.y;
      aux << ". Press CTRL + T to turn off.";
      break;
   }
   _window.status()->showMessage(QString::fromStdString(aux.str()), 1000);
}

void ViewMediator::sendDeltaFactor(const int factor)
{
   handler->pointMapper().setDeltaFactor(factor);
   handler->createZoomCmd();
}

void ViewMediator::sendMessage(std::string msg)
{
   _window.status()->showMessage(QString::fromStdString(msg), 1000);
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
