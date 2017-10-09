#pragma once

#include "Vector2.h"
#include "GraphicsSystem.h"
#include "Rect2d.h"

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

      const Vector2f& getPosition() const
      {
         return m_rect.getPosition();
      }

      void setPosition(const Vector2f& newPosition)
      {
         m_rect.setPosition(newPosition);
      }

      void setVelocity(const Vector2f& newVelocity)
      {
         m_velocity = Vector2f(newVelocity);
      }

      const Vector2f& getVelocity() const
      {
         return m_velocity;
      }

      const Rect2D& getRect() const
      {
         return m_rect;
      }

      virtual void update(const float& deltaTime) = 0;
      virtual void draw(GraphicsSystem& graphics) = 0;

   protected:
      Vector2f m_velocity;
      Rect2D m_rect;
   };
   
}

