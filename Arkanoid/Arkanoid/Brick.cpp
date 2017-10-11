#include "Brick.h"

namespace Arkanoid
{
   Brick::Brick(const Rect2D rect, const Color color) : /*m_rect{ rect },*/ m_color{ color }
   {
      m_rect = rect;
   }

   void Brick::update(const float& deltaTime)
   {
   }

   void Brick::draw(GraphicsSystem& graphics)
   {
      graphics.drawFilledBox(m_rect, m_color);
   }

}

