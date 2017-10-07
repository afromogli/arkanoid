#pragma once

#include <memory>
#include <vector>

#include "Vector2.h"
#include "NotImplementedException.h"
#include "GraphicsSystem.h"
#include "Rect2d.h"
#include "GameConfig.h"

using namespace std;

namespace Arkanoid {

   // Abstract base entity class
   // NOTE: DON'T CREATE Entity.cpp, this will break sub classes because of templating
   class Entity
   {
   protected:

      Entity() : m_velocity(Vector2f::Zero) {
      }

   public:

      virtual ~Entity() {}
      inline const Vector2f& getPosition() const
      {
         return m_rect.getPosition();
      }
      inline void setPosition(const Vector2f& newPosition)
      {
         m_rect.setPosition(newPosition);
      }

      inline void setVelocity(const Vector2f& newVelocity)
      {
         m_velocity = Vector2f(newVelocity);
      }

      inline const Vector2f& getVelocity() const
      {
         return m_velocity;
      }

      inline const Rect2d& getRect() const
      {
         return m_rect;
      }

      virtual void update(const float& deltaTime) = 0;
      virtual void draw(GraphicsSystem& graphics) = 0;

   protected:
      Vector2f m_velocity;
      Rect2d m_rect;
   };
   
}

