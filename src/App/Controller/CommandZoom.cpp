#include "CommandZoom.h"
#include "PointMapper.h"
#include "CADFileManager.h"
#include "ViewMediator.h"

void CommandZoom::execute(CADFileManager& fileManager, ViewMediator& viewMediator)
{
   auto zoomedShapes= mapper.transformShapes(fileManager.current());

   viewMediator.canvas().clearMap();

   for (auto& shape : zoomedShapes) {
      viewMediator.canvas().drawCanvas(*shape);
   }
}