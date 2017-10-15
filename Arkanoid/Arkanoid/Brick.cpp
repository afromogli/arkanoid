#include "Brick.h"
#include "GameConfig.h"
#include <cassert>

namespace Arkanoid
{
   Brick::Brick(const Rect2D rect, const Color color) : /*m_rect{ rect },*/ m_color{ color }
   {
      m_rect = rect;
   }

   void Brick::update(const float& deltaTime)
   {
   }

   void Brick::draw(Graphics& graphics)
   {
      if (m_isAlive)
      {
         graphics.drawFilledBox(m_rect, m_color);
      }
   }

   bool Brick::isColliding(const EBall& ball) const
   {
      return m_rect.intersects(ball.getRect());
   }

   void Brick::doBallCollision(EBall& ball)
   {
      assert(isColliding(ball));

      // if ball is below or above the brick, negate the y-direction
      if (ball.getPosition().x >= getPosition().x || ball.getPosition().x <= (getPosition().x + getRect().getWidth()))
      {
         ball.setVelocity(Vector2f(ball.getVelocity().x, ball.getVelocity().y*-1));
      }
      // ball has hit left or right side of the brick, negate the x-direction
      else
      {
         ball.setVelocity(Vector2f(ball.getVelocity().x*-1, ball.getVelocity().y));
      }
      m_isAlive = false;
   }

   bool Brick::isAlive() const
   {
      return m_isAlive;
   }

   void Brick::setIsAlive()
   {
      m_isAlive = true;
   }
}

