#include "Rect2d.h"

using namespace std;

namespace Arkanoid {
   bool Rect2D::intersects(const Rect2D& otherBBox) const {
      const float xDiff = fabs((m_position.x + m_width / 2)- (otherBBox.m_position.x + otherBBox.getWidth() / 2));
      const float yDiff = fabs((m_position.y + m_height / 2) - (otherBBox.m_position.y+ otherBBox.getHeight() / 2));

      const bool xIntersects = xDiff < (m_width/2 + otherBBox.getWidth()/2);
      const bool yIntersects = yDiff < (m_height/2 + otherBBox.getHeight()/2);


     /* cout << "xDiff: " << xDiff << "\n";
      cout << "yDiff: " << yDiff << "\n";
      cout << "width/2 + otherBBox.getWidth()/2: " << (width / 2 + otherBBox.getWidth() / 2) << "\n";
      cout << "height/2 + otherBBox.getHeight()/2: " << (height / 2 + otherBBox.getHeight() / 2) << "\n";
*/
      return xIntersects && yIntersects;
   }

   Vector2f Rect2D::getCenter() const
   {
      return Vector2f(m_position.x + m_width / 2, m_position.y + m_height / 2);
   }
}

