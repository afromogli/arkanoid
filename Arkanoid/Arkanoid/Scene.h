#pragma once

#include "Graphics.h"
#include <SDL2/SDL_hints.h>

namespace Arkanoid {
   class Scene
   {
   public:
      Scene() {}
      virtual ~Scene() {}

      virtual void handleInput(const Uint8 *keyboardState) = 0;
      virtual void update(const float& deltaTime) = 0;
      virtual void draw(Graphics& graphics) = 0;
   };
}
