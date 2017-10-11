#include "Brick.h"

namespace Arkanoid
{
   Brick::Brick(const Color color) : m_color(color)
   {
   }

   void Brick::update(const float& deltaTime)
   {
   }

   void Brick::draw(GraphicsSystem& graphics)
   {
      graphics.drawFilledBox(m_rect, m_color);
   }

}

