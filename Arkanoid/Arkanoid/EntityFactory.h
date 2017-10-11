#pragma once

#include <memory>
#include "GraphicsSystem.h"
#include "Entity.h"

using namespace std;

namespace Arkanoid 
{
   enum EntityType { Ball, Paddle };

   class EntityFactory
   {
   public:
      EntityFactory(GraphicsSystem& graphicsSystem) : 
         m_graphicsSystem{graphicsSystem}
      {
      }
      shared_ptr<Entity> createEntity(const EntityType &type) const;

   private:
      static shared_ptr<Entity> createBallEntity();
      static shared_ptr<Entity> createPaddleEntity();

      GraphicsSystem& m_graphicsSystem;
   };
}

