#include "Board.h"
#include <iostream>
#include <cassert>

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

   void Board::update(EBall& ball, const float deltaTime) const
   {
      // TODO: Do collision detection
      // Loop through all bricks and save closest collision if there is any
      for (int x = 0; x < GameConfig::BoardColumns; x++)
      {
         for (int y = 0; y < GameConfig::BoardRows; y++)
         {
            Brick& currBrick = m_bricks[y * GameConfig::BoardColumns + x];
            if (currBrick.isAlive() && currBrick.isColliding(ball))
            {
               currBrick.doBallCollision(ball);
               assert(currBrick.isAlive() == false);
            }
         }
      }
      // TODO: Only do collision with the closest brick and kill the brick which collided
   }

   void Board::draw(GraphicsSystem& graphics) const
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

