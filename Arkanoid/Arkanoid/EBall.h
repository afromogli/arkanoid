#pragma once

#include "Entity.h"
#include <memory>

using namespace std;

namespace Arkanoid {
   class EntityFactory;

   class EBall : public Entity {
      friend class EntityFactory;
   public:
      void update(const float& deltaTime) override;
      void draw(GraphicsSystem& graphics) override;

      static constexpr float Maxbounceangle = 15;
      bool isMoving() const;

   private:
      EBall();
      int m_ballHits;

   };
}

