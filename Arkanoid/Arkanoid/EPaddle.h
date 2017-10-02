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
      void update(const float& deltaTime);
      void draw(GraphicsSystem& graphics);
      bool IsColliding(const EBall& ball) const;
      void DoBallCollision(EBall& ball);
   private:
      EPaddle();
   };
}

