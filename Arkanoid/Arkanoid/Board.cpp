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

   bool Board::doBrickCollisions(EBall& ball) const
   {
      int closestBrickIndex = -1;
      float closestBrickDistance = -1;
      
      // Loop through all bricks and save closest collision if there is any
      for (int x = 0; x < GameConfig::BoardColumns; x++)
      {
         for (int y = 0; y < GameConfig::BoardRows; y++)
         {
            Brick& currBrick = m_bricks[y * GameConfig::BoardColumns + x];
            if (currBrick.isAlive() && currBrick.isColliding(ball))
            {
               const float distance = ball.getRect().getCenter().distanceTo(currBrick.getRect().getCenter());
               if (closestBrickDistance == -1 || distance < closestBrickDistance)
               {
                  closestBrickDistance = distance;
                  closestBrickIndex = y * GameConfig::BoardColumns + x;
                  assert(closestBrickDistance > 0);
               }
            }
         }
      }

      // Only do collision with the closest brick
      if (closestBrickIndex != -1)
      {
         Brick& closestBrick = m_bricks[closestBrickIndex];
         closestBrick.doBallCollision(ball);
         assert(closestBrick.isAlive() == false);
         return true;
      }
      return false;
   }

   Walls::BallCollisionResult Board::doWallCollisions(EBall& ball, EPaddle& paddle) const
   {
      m_walls.doPaddleCollision(paddle);
      return m_walls.doBallCollision(ball);
   }

   void Board::draw(Graphics& graphics)
   {
      m_walls.draw(graphics);

      for (int x = 0; x < GameConfig::BoardColumns; x++)
      {
         for (int y = 0; y < GameConfig::BoardRows; y++)
         {
            m_bricks[y*GameConfig::BoardColumns + x].draw(graphics);
         }
      }
      
   }

   bool Board::hasAnyAliveBricks() const
   {
      for (int i = 0; i < GameConfig::BoardColumns * GameConfig::BoardRows; i++)
      {
         if (m_bricks[i].isAlive())
         {
            return true;
         }  
      }
      return false;
   }

   void Board::reset() const
   {
      for (int i = 0; i < GameConfig::BoardColumns * GameConfig::BoardRows; i++)
      {
         m_bricks[i].setIsAlive();
      }
   }
}

