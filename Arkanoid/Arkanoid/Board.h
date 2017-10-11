#pragma once

#include "Brick.h"
#include "GameConfig.h"

namespace Arkanoid
{
   class Board : public Object
   {
   public:
      Board(const Vector2f upperLeftPos);
      ~Board();

      void update(const float& deltaTime) override;
      void draw(GraphicsSystem& graphics) override;

   private:
      Brick* m_bricks;
      static constexpr Color BricksColors[4] = { { 230,0,0 },{ 0,230,0 },{ 0,0,230 },{ 0,230,230 } };


   };
}