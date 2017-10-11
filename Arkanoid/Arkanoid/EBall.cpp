#include "EBall.h"
#include "GameConfig.h"

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
      graphics.drawFilledCircle(getPosition(), GameConfig::BallDiameter, Colors::White);
   }
}