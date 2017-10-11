#include "Board.h"
#include <iostream>
namespace Arkanoid
{
   Board::Board(const Vector2f upperLeftPos)
   {
      m_bricks = new Brick[GameConfig::BoardColumns * GameConfig::BoardRows];
      
      for (int y = 0; y < GameConfig::BoardRows; y++)
      {
         for (int x = 0; x < GameConfig::BoardColumns; x++)
         {
            const Vector2f brickPosition = Vector2f(
               upperLeftPos.x + x*GameConfig::BrickWidth + x*GameConfig::BrickSpacing, 
               upperLeftPos.y + y*GameConfig::BrickHeight + y*GameConfig::BrickSpacing);

            const Rect2D rect = Rect2D(brickPosition, int(GameConfig::BrickWidth), int(GameConfig::BrickHeight));
            m_bricks[y*GameConfig::BoardColumns + x] = Brick(rect, BricksColors[y]);
         }
      }
   }
   Board::~Board()
   {
      delete [] m_bricks;
      m_bricks = nullptr;
   }

   void Board::update(const float& deltaTime)
   {
   }

   void Board::draw(GraphicsSystem& graphics)
   {
      for (int x = 0; x < GameConfig::BoardColumns; x++)
      {
         for (int y = 0; y < GameConfig::BoardRows; y++)
         {
            m_bricks[y*GameConfig::BoardColumns + x].draw(graphics);
         }
      }
   }
}

