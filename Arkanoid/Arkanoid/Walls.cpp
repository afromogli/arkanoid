#include "Walls.h"

namespace Arkanoid
{
   void Walls::doBallCollision(EBall& ball) const
   {
      const Rect2D& ballRect = ball.getRect();
      const Vector2f& currBallVel = ball.getVelocity();
      // Upper
      // Bottom
      if (m_walls[0].intersects(ballRect) || m_walls[1].intersects(ballRect))
      {
         ball.setVelocity(Vector2f(currBallVel.x, currBallVel.y*-1));
      }
      
      // Left
      // Right
      else if (m_walls[2].intersects(ballRect) || m_walls[3].intersects(ballRect))
      {
         ball.setVelocity(Vector2f(currBallVel.x*-1, currBallVel.y));
      }
   }

   void Walls::doPaddleCollision(EPaddle& paddle) const
   {
      // Left
      if (m_walls[2].intersects(paddle.getRect()))
      {
         paddle.setPosition(Vector2f(GameConfig::WallThickness, paddle.getPosition().y));
      }
      // Right
      else if (m_walls[3].intersects(paddle.getRect()))
      {
         paddle.setPosition(Vector2f(GameConfig::WinSize.x - GameConfig::WallThickness - GameConfig::PaddleSize.x, paddle.getPosition().y));
      }
   }

   void Walls::update(const float& deltaTime)
   {
   }

   void Walls::draw(GraphicsSystem& graphics)
   {
      for (const Rect2D wall : m_walls)
      {
         graphics.drawFilledBox(wall, Colors::DarkBlue);
      }
   }
}
