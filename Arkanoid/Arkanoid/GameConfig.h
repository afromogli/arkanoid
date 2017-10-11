#pragma once

#include "Vector2.h"

namespace Arkanoid
{
   class GameConfig
   {
   public:
      // Engine and window configuration
      static constexpr float MsPerUpdate = 4.0f; 
      static Vector2f WinInitPos;
      static Vector2f WinSize;

      // Main scene configuration
      static Vector2f InitialPlayerPaddlePosition;
      static Vector2f InitialCpuPaddlePosition;

      static constexpr float BallSpeed = 250.0f;
      static constexpr float BallSpeedIncPerHit = 12.0f;

      static constexpr int BallDiameter = 5;
      static Vector2f PaddleSize;
      static constexpr float PaddleSpeed = 300.0; // Pixels per second;

      static constexpr float BrickWidth = 30;
      static constexpr float BrickHeight = 10;

      static constexpr unsigned int BoardColumns = 20;
      static constexpr unsigned int BoardRows = 5;
      static constexpr float BrickSpacing = 1;

   private:
      GameConfig() {}
   };
}
