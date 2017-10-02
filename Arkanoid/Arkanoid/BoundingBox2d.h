#pragma once

#include "Vector2.h"
#include <assert.h>

namespace Arkanoid {
   class BoundingBox2d {
   private:
      int width;
      int height;
      // The position is treated as the upper left corner of the bounding box
      Vector2f position;

   public:
      BoundingBox2d() {
         width = 0;
         height = 0;
         position = Vector2f();
      }

      BoundingBox2d(const Vector2f& position, const int& width, const int& height) {
         this->width = width; 
         this->height = height;
         this->position = position;
      }

      bool intersects(const BoundingBox2d& otherBBox) const;

      const Vector2f& getPosition() const {
         return position;
      }

      void setPosition(const Vector2f& position) {
         this->position = position;
      }

      const int& getWidth() const {
         return width;
      }

      const int& getHeight() const {
         return height;
      }

      void setSize(const int& width, const int& height)
      {
         this->width = width;
         this->height = height;
      }
   };
}
