#pragma once

#include "Vector2.h"

namespace Arkanoid {
   class Rect2D {
   public:
      Rect2D() {
         m_width = 0;
         m_height = 0;
         m_position = Vector2f();
      }

      Rect2D(const Vector2f& position, const int& width, const int& height) {
         this->m_width = width; 
         this->m_height = height;
         this->m_position = position;
      }

      bool intersects(const Rect2D& otherBBox) const;

      const Vector2f& getPosition() const {
         return m_position;
      }

      void setPosition(const Vector2f& position) {
         this->m_position = position;
      }

      const int getWidth() const {
         return m_width;
      }

      const int getHeight() const {
         return m_height;
      }

      void setSize(const int width, const int height)
      {
         this->m_width = width;
         this->m_height = height;
      }

   private:
      int m_width;
      int m_height;
      // The position is treated as the upper left corner of the bounding box
      Vector2f m_position;
   };
}
