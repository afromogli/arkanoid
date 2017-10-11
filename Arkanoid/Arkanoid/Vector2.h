#pragma once

#include <string>

namespace Arkanoid
{
   class Vector2f
   {
   public:
      constexpr Vector2f() : x(0), y(0) {}
      constexpr Vector2f(const float xPos, const float yPos) : x(xPos), y(yPos) {}
      constexpr Vector2f(const Vector2f& other) : x(other.x), y(other.y) {}

      float x;
      float y;

      bool operator==(const Vector2f& otherVec) const
      {
         if (this == &otherVec) {
            return true;
         }
         return x == otherVec.x && y == otherVec.y;
      }

      Vector2f operator*(const Vector2f& otherVec) const
      {
         return Vector2f(x*otherVec.x, y*otherVec.y);
      }

      Vector2f operator*(const float value) const 
      {
         return Vector2f(x*value, y*value);
      }

      Vector2f operator+(const Vector2f& otherVec) const 
      {
         return Vector2f(x+otherVec.x, y+otherVec.y);
      }

      Vector2f& operator+=(const Vector2f& otherVec) 
      {
         x += otherVec.x;
         y += otherVec.y;
         return *this;
      }

      Vector2f operator/(const float denominator) const
      {
         return Vector2f(x / denominator, y / denominator);
      }

      float distanceTo(const Vector2f& otherVec) const;
      const float length() const;
      Vector2f getNormalized() const;
      static Vector2f Zero;

      static Vector2f Vector2f::getRandomizedVector(int xMinValue, int xMaxValue, int yMinValue, int yMaxValue);
      static int getRandomValue(int minValue, int maxValue);

      std::string toString() const;
   };
}
