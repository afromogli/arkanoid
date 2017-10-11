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
      const float relativeIntersectY = (getPosition().y + GameConfig::PaddleSize.y / 2) - ball.getPosition().y;
      const float normalizedRelativeIntersectionY = (relativeIntersectY / (GameConfig::PaddleSize.y / 2));
      const float bounceAngle = normalizedRelativeIntersectionY * EBall::Maxbounceangle * static_cast<float>(PI) / 180.0f;

      //ball.incBallSpeed();
      const float currentBallSpeed = GameConfig::BallSpeed;
      float ballVx, ballVy;
      if (getPosition().x < GameConfig::WinSize.x / 2)
      {
         ballVx = currentBallSpeed*cos(bounceAngle);
         ballVy = currentBallSpeed*-sin(bounceAngle);
      }
      else
      {
         ballVx = currentBallSpeed*cos(bounceAngle)*-1;
         ballVy = currentBallSpeed*sin(bounceAngle)*-1;
      }
      ball.setVelocity(Vector2f(ballVx, ballVy));
   }
}