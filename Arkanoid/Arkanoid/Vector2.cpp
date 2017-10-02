#include "Vector2.h"
#include <random>
#include "xorshift.h"

namespace Arkanoid
{
   Vector2f Vector2f::Zero = Vector2f(0, 0);
   
   inline float Vector2f::distanceTo(const Vector2f & otherVec) const
   {
      float xDiff = otherVec.x - this->x;
      float yDiff = otherVec.y - this->y;
      return sqrt(xDiff*xDiff + yDiff*yDiff);
   }

   inline const float Vector2f::length() const
   {
      return sqrt(x*x + y*y);
   }

   Vector2f Vector2f::getNormalized() const
   {
      return *this / length();
   }

   Vector2f Vector2f::getRandomizedVector(int xMinValue, int xMaxValue, int yMinValue, int yMaxValue)
   {
      return Vector2f(float(getRandomValue(xMinValue, xMaxValue)), float(getRandomValue(yMinValue, yMaxValue)));
   }
   
   int Vector2f::getRandomValue(int minValue, int maxValue)
   {
      std::random_device rd;
      xorshift gen(rd());
      std::uniform_int_distribution<> dist(minValue, maxValue);
      return dist(gen);
   }

   inline std::string Vector2f::toString() const
   {
      std::ostringstream outStream;
      outStream << "x: ";
      outStream << x;
      outStream << " y: ";
      outStream << y;
      return outStream.str();
   }
}
