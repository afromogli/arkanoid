#include "EPaddle.h"
#include "GameConfig.h"
#include "Math.h"

namespace Arkanoid
{
   EPaddle::EPaddle() : Entity()
   {
      m_rect.setSize(int(GameConfig::PaddleSize.x), int(GameConfig::PaddleSize.y));
   }

   void EPaddle::update(const float & deltaTime)
   {
      const float deltaSeconds = deltaTime / 1000;
      const Vector2f nextPosition = getPosition() + m_velocity*deltaSeconds;
      if ((nextPosition.y) > 0 && (nextPosition.y + m_rect.getHeight()) < GameConfig::WinSize.y) {
         setPosition(nextPosition);
      }
   }

   void EPaddle::draw(GraphicsSystem & graphics)
   {
      graphics.drawFilledRoundedBox(m_rect, 2, Colors::DarkGrey);
   }

   bool EPaddle::isColliding(const EBall& ball) const
   {
      return m_rect.intersects(ball.getRect());
   }

   void EPaddle::doBallCollision(EBall& ball) const
   {
      const float relativeIntersectX = getRect().getCenter().x - ball.getPosition().x;
      const float normalizedRelativeIntersectionX = (relativeIntersectX / (getRect().getWidth() / 2));
      const float bounceAngle = normalizedRelativeIntersectionX * EBall::Maxbounceangle * float(PI) / 180.0f;

      const float currentBallSpeed = GameConfig::BallSpeed;
      const float ballVy = currentBallSpeed*cos(bounceAngle)*-1;
      const float ballVx = currentBallSpeed*sin(bounceAngle)*-1;

      ball.setVelocity(Vector2f(ballVx, ballVy));       
   }
}