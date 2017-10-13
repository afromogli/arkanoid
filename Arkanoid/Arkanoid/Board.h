#pragma once

#include "Brick.h"
#include "GameConfig.h"
#include "EBall.h"
#include "Walls.h"
#include "EPaddle.h"

namespace Arkanoid
{
   class Board
   {
   public:
      Board(const Vector2f upperLeftPos);
      ~Board();

      void doBrickCollisions(EBall& ball) const;
      Walls::BallCollisionResult doWallCollisions(EBall& ball, EPaddle& paddle) const;
      void draw(GraphicsSystem& graphics);

   private:
      Brick* m_bricks;
      static constexpr Color BricksColors[GameConfig::BoardRows] = { { 230,0,0 },{ 0,230,0 },{ 0,0,230 },{ 0,230,230 } };
      Walls m_walls;
   };
}
