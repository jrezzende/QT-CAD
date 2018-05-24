#include "CommandZoom.h"
#include "PointMapper.h"
#include "CADFileManager.h"
#include "ViewMediator.h"

void CommandZoom::execute(CADFileManager& fmanager, ViewMediator& vmediator)
{
   auto shapes= mapper.transformShapes(fmanager.currentFile());
   vmediator.canvas().clearMap();

   for (auto& shape : shapes) {
      vmediator.canvas().drawCanvas(*shape);
   }
}