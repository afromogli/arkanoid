#pragma once

#include "Vector2.h"

namespace Arkanoid
{
   class GameConfig
   {
   public:
      // Engine and window configuration
      static constexpr float MsPerUpdate = 4.0f; 
      static constexpr Vector2f WinInitPos = Vector2f(300, 300);
      static constexpr Vector2f WinSize = Vector2f(1024, 768);

      // Main scene configuration
      static constexpr Vector2f InitialPlayerPaddlePosition = Vector2f(GameConfig::WinSize.x - 20, GameConfig::WinSize.y / 2 - 5);

      static constexpr float BallSpeed = 250.0f;
      static constexpr float BallSpeedIncPerHit = 12.0f;

      static constexpr int BallDiameter = 5;
      static constexpr Vector2f GameConfig::PaddleSize = Vector2f(10, 60);
      static constexpr float PaddleSpeed = 300.0; // Pixels per second;

      static constexpr float BrickWidth = 40;
      static constexpr float BrickHeight = 20;

      static constexpr unsigned int BoardColumns = 20;
      static constexpr unsigned int BoardRows = 5;
      static constexpr float BrickSpacing = 4;
      static constexpr Vector2f BoardUpperLeftPos = Vector2f(60.f, 5.f);

   private:
      GameConfig() {}
   };
}
