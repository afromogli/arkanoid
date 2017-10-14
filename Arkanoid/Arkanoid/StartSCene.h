#pragma once

#include "Scene.h"

namespace Arkanoid
{
   class StartScene : public Scene
   {
      void handleInput(const Uint8 *keyboardState) override;
      void update(const float& deltaTime) override;
      void draw(Graphics& graphics) override;
   };
} 