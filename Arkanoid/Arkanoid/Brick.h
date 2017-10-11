#pragma once

#include "Entity.h"

namespace Arkanoid
{
   class Brick : Entity
   {
   public:
      Brick() = default;
      Brick(const Rect2D rect, const Color color);
      void update(const float& deltaTime) override;
      void draw(GraphicsSystem& graphics) override;
   private:
      Color m_color;
   };
}