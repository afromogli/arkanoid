#include "Rect2d.h"
#include <math.h>
#include <iostream>

using namespace std;

namespace Arkanoid {
   bool Rect2d::intersects(const Rect2d& otherBBox) const {
      float xDiff = fabs((position.x + width / 2)- (otherBBox.position.x + otherBBox.getWidth() / 2));
      float yDiff = fabs((position.y + height / 2) - (otherBBox.position.y+ otherBBox.getHeight() / 2));

      bool xIntersects = xDiff < (width/2 + otherBBox.getWidth()/2);
      bool yIntersects = yDiff < (height/2 + otherBBox.getHeight()/2);


     /* cout << "xDiff: " << xDiff << "\n";
      cout << "yDiff: " << yDiff << "\n";
      cout << "width/2 + otherBBox.getWidth()/2: " << (width / 2 + otherBBox.getWidth() / 2) << "\n";
      cout << "height/2 + otherBBox.getHeight()/2: " << (height / 2 + otherBBox.getHeight() / 2) << "\n";
*/
      return xIntersects && yIntersects;
   }
}

