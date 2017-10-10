#pragma once

#include "Entity.h"

namespace Arkanoid
{
   class Brick : Entity
   {
   public:
      virtual void update(const float& deltaTime) override;
      virtual void draw(GraphicsSystem& graphics) override;
   };
}