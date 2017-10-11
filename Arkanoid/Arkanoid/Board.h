#pragma once

#include "Brick.h"
#include "GameConfig.h"
#include "EBall.h"

namespace Arkanoid
{
   class Board
   {
   public:
      Board(const Vector2f upperLeftPos);
      ~Board();

      void update(EBall& ball, const float deltaTime) const;
      void draw(GraphicsSystem& graphics) const;

   private:
      Brick* m_bricks;
      static constexpr Color BricksColors[4] = { { 230,0,0 },{ 0,230,0 },{ 0,0,230 },{ 0,230,230 } };
   };
}