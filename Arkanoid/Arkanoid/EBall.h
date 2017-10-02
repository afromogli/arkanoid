#pragma once

#include "Entity.h"
#include <memory>

using namespace std;

namespace Arkanoid {
   class EntityFactory;

   class EBall : public Entity {
      friend class EntityFactory;
   public:
      void update(const float& deltaTime);
      void draw(GraphicsSystem& graphics);

      //void incBallSpeed();
      void resetBallSpeed();

      float getCurrentSpeed() const;

      static constexpr float MAXBOUNCEANGLE = 15;

   private:
      EBall();
      int m_ballHits;

   };
}

