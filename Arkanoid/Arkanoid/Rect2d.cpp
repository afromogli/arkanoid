#include "Rect2d.h"

using namespace std;

namespace Arkanoid {
   bool Rect2D::intersects(const Rect2D& otherBBox) const {
      float xDiff = fabs((m_position.x + m_width / 2)- (otherBBox.m_position.x + otherBBox.getWidth() / 2));
      float yDiff = fabs((m_position.y + m_height / 2) - (otherBBox.m_position.y+ otherBBox.getHeight() / 2));

      bool xIntersects = xDiff < (m_width/2 + otherBBox.getWidth()/2);
      bool yIntersects = yDiff < (m_height/2 + otherBBox.getHeight()/2);


     /* cout << "xDiff: " << xDiff << "\n";
      cout << "yDiff: " << yDiff << "\n";
      cout << "width/2 + otherBBox.getWidth()/2: " << (width / 2 + otherBBox.getWidth() / 2) << "\n";
      cout << "height/2 + otherBBox.getHeight()/2: " << (height / 2 + otherBBox.getHeight() / 2) << "\n";
*/
      return xIntersects && yIntersects;
   }
}

