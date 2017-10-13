#pragma once

#include "Entity.h"
#include <memory>
#include "EBall.h"

using namespace std;

namespace Arkanoid 
{
   class EntityFactory;

   class EPaddle : public Entity {
      friend class EntityFactory;
   public:
      void update(const float& deltaTime) override;
      void draw(GraphicsSystem& graphics) override;
      bool isColliding(const EBall& ball) const;
      void doBallCollision(EBall& ball) const;
   private:
      EPaddle();

   };
}

