#include "EBall.h"
#include "GameConfig.h"
#include <SDL2_gfxPrimitives.h>

namespace Arkanoid {   
   

   EBall::EBall() : m_ballHits{0}
   {
      m_rect.setSize(GameConfig::BallDiameter, GameConfig::BallDiameter);
   }

   void EBall::update(const float& deltaTime)
   {
      const float deltaSeconds = deltaTime / 1000;
      const Vector2f nextPosition = getPosition() + m_velocity*deltaSeconds;
      setPosition(nextPosition);
   }

   void EBall::draw(GraphicsSystem& graphics)
   {
      const Vector2f& position = getPosition();
      filledCircleRGBA(graphics.getRenderer(), static_cast<Sint16>(position.x), static_cast<Sint16>(position.y), GameConfig::BallDiameter, 255, 255, 255, 255);
   }

   /*void EBall::incBallSpeed()
   {
      m_ballHits++;
   }*/

   void EBall::resetBallSpeed()
   {
      m_ballHits = 0;
   }

   float EBall::getCurrentSpeed() const
   {
      return GameConfig::BallSpeed + m_ballHits * GameConfig::BallSpeedIncPerHit;
   }
}