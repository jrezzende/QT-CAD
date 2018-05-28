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
      handler_->mousePressEvent(p);
      sendMouseMessages(PRESS, p);
      break;
   case MOVE:
      handler_->mouseMoveEvent(p);
      sendMouseMessages(MOVE, p);
      break;
   case RELEASE:
      handler_->mouseReleaseEvent(p);
      sendMouseMessages(RELEASE, p);
      break;
   case WHEEL:
      sendMouseMessages(WHEEL, p);
      break;
   case TRACKING:
      sendMouseMessages(TRACKING, p);
      break;
   case RIGHTCLICK:
      handler_->rightClickEvent(p);
      break;
   }
}

void ViewMediator::sendShapeEvents(const ShapeType st) const
{
   switch(st)
   {
   case LINE:
      handler_->createLineCommand();
      break;
   case BEZIER:
      handler_->createBezierCommand();
      break;
   case ARC:
      handler_->createArcCommand();
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
   handler_->pointMapper().setDeltaFactor(factor);
   handler_->createZoomCmd();
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
      handler_->createNewFileCmd();
      handler_->createLineCommand();
      break;
   case LOAD:
      handler_->createLoadFileCmd();
      break;
   case SAVE:
      handler_->createSaveFileCmd();
      break;
   case UNDO:
      handler_->eraseLastShape();
      break;
   case REDO:
      handler_->redoShape();
      break;
   case CLEAR:
      handler_->clearShapes();
      break;
   case EXIT:
      handler_->createExitFileCmd();
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
