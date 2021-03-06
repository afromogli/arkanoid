#pragma once

#include "Entity.h"
#include "EBall.h"

namespace Arkanoid
{
   class Brick : public Entity
   {
   public:
      Brick() = default;
      Brick(const Rect2D rect, const Color color);
      void update(const float& deltaTime) override;
      void draw(Graphics& graphics) override;

      bool isColliding(const EBall& ball) const;
      void doBallCollision(EBall& ball);

      bool isAlive() const;
      void setIsAlive();
   private:
      Color m_color;
      bool m_isAlive = true;
   };
}