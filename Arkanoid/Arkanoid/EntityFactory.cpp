#include <string>

#include "NotSupportedException.h"
#include "EntityFactory.h"

#include "EBall.h"
#include "EPaddle.h"

namespace Arkanoid
{
   shared_ptr<Entity> EntityFactory::createEntity(const EntityType& type) const
   {
      shared_ptr<Entity> entity = nullptr;
      switch (type)
      {
      case EntityType::Ball:
         entity = this->createBallEntity();
         break;
      case EntityType::Paddle:
         entity = this->createPaddleEntity();
         break;
      default:
         throw new NotSupportedException("The EntityType: " + std::to_string(type) + " is not supported");
      }
      return entity;
   }

   shared_ptr<Entity> EntityFactory::createBallEntity()
   {
      return shared_ptr<Entity>(new EBall());
   }

   shared_ptr<Entity> EntityFactory::createPaddleEntity()
   {
      return shared_ptr<Entity>(new EPaddle());
   }
}


