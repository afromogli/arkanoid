#pragma once

#include <memory>
#include "Graphics.h"
#include "Entity.h"

using namespace std;

namespace Arkanoid 
{
   enum EntityType { Ball, Paddle };

   class EntityFactory
   {
   public:
      EntityFactory(Graphics& graphics) : 
         m_graphics{graphics}
      {
      }
      shared_ptr<Entity> createEntity(const EntityType &type) const;

   private:
      static shared_ptr<Entity> createBallEntity();
      static shared_ptr<Entity> createPaddleEntity();

      Graphics& m_graphics;
   };
}

