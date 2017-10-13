#pragma once

#include "EBall.h"
#include "GameConfig.h"
#include "EPaddle.h"

namespace Arkanoid
{
   class Walls : public Object
   {
   public:
      enum BallCollisionResult { Inside = 1, Outside = 2};
      BallCollisionResult doBallCollision(EBall& ball) const;
      void doPaddleCollision(EPaddle& paddle) const;

      void update(const float& deltaTime) override;
      void draw(GraphicsSystem& graphics) override;

   private:
      Rect2D m_walls[4] = {
         // The walls do not cover each other in the corners
         { Vector2f(0, 0), int(GameConfig::WinSize.x), int(GameConfig::WallThickness) }, // Upper
         { Vector2f(0, GameConfig::WinSize.y - GameConfig::WallThickness), int(GameConfig::WinSize.x), int(GameConfig::WallThickness) }, // Bottom

         { Vector2f(0, GameConfig::WallThickness), int(GameConfig::WallThickness), int(GameConfig::WinSize.y - GameConfig::WallThickness) }, // Left
         { Vector2f(GameConfig::WinSize.x - GameConfig::WallThickness, GameConfig::WallThickness), int(GameConfig::WallThickness), int(GameConfig::WinSize.y - GameConfig::WallThickness) } // Right
      };
   };
}
