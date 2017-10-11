#pragma once

#include "Entity.h"

namespace Arkanoid
{
   class Brick : Entity
   {
   public:
      Brick(const Color color);
      void update(const float& deltaTime) override;
      void draw(GraphicsSystem& graphics) override;
   private:
      Color m_color;
   };
}