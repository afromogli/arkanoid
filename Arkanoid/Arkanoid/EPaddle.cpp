#include "EPaddle.h"
#include "GameConfig.h"
#include <SDL2\SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "Math.h"

namespace Arkanoid
{
   EPaddle::EPaddle() : Entity()
   {
      m_rect.setSize((int)GameConfig::PaddleSize.x, (int)GameConfig::PaddleSize.y);
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
      // Treated as the paddles upper left position
      const Vector2f& position = getPosition();
      const Vector2f start = Vector2f(position.x, position.y);
      const Vector2f end = Vector2f(position.x + GameConfig::PaddleSize.x, position.y + GameConfig::PaddleSize.y);
      roundedBoxRGBA(graphics.getRenderer(), (Sint16)start.x, (Sint16)start.y, (Sint16)end.x, (Sint16)end.y, 2, 255, 255, 255, 255);
   }

   bool EPaddle::isColliding(const EBall& ball) const
   {
      return ball.getRect().intersects(getRect());
   }

   void EPaddle::doBallCollision(EBall& ball) const
   {
      const float relativeIntersectY = (getPosition().y + GameConfig::PaddleSize.y / 2) - ball.getPosition().y;
      const float normalizedRelativeIntersectionY = (relativeIntersectY / (GameConfig::PaddleSize.y / 2));
      const float bounceAngle = normalizedRelativeIntersectionY * EBall::Maxbounceangle * static_cast<float>(PI) / 180.0f;

      //ball.incBallSpeed();
      const float currentBallSpeed = ball.getCurrentSpeed();
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