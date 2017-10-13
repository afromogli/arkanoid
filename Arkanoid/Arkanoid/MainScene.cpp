#include "MainScene.h"
#include "Engine.h"
#include <iostream>
#include <SDL2/SDL.h>

namespace Arkanoid
{
   MainScene::MainScene(GraphicsSystem& graphics, AudioSystem& audioSystem) : 
      m_board{ GameConfig::BoardUpperLeftPos }, 
      m_graphics{ graphics }, 
      m_audioSystem{ audioSystem }
   {
      m_paddle = std::dynamic_pointer_cast<EPaddle>(Engine::entityFactoryInstance->createEntity(EntityType::Paddle));
      m_ball = std::dynamic_pointer_cast<EBall>(Engine::entityFactoryInstance->createEntity(EntityType::Ball));
      
      m_paddle->setPosition(GameConfig::InitialPlayerPaddlePosition);
      positionBallAbovePaddle();

      m_allEntities.push_back(m_paddle);
      m_allEntities.push_back(m_ball);

      m_brickSound = audioSystem.createAndLoadAudioClip("Sounds\\arkbrick.wav");
      m_paddleSound = audioSystem.createAndLoadAudioClip("Sounds\\arkpad.wav");
   }

   MainScene::~MainScene()
   {

   }

   void MainScene::handleInput(const Uint8 *state)
   {
      if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_RIGHT])
      {
         m_paddle->setVelocity(Vector2f::Zero);
      }
      else if (state[SDL_SCANCODE_LEFT])
      {
         m_paddle->setVelocity(Vector2f(-GameConfig::PaddleSpeed, 0));
      }
      else if (state[SDL_SCANCODE_RIGHT])
      {
         m_paddle->setVelocity(Vector2f(GameConfig::PaddleSpeed, 0));
      }
      else
      {
         m_paddle->setVelocity(Vector2f::Zero);
      }
      
      if (state[SDL_SCANCODE_SPACE])
      {
         if (m_ball->getVelocity().length() <= 0)
         {
            m_ball->setVelocity(Vector2f(5, -GameConfig::BallSpeed));
            m_paddleCooldown = GameConfig::PaddleCooldown;
         }
      }
   }
   

   void MainScene::update(const float& deltaTime)
   {
      EBall& ball = *m_ball;
      EPaddle &paddle = *m_paddle;

      for (auto entity : m_allEntities)
      {
         entity->update(deltaTime);
      }

      if (m_board.doBrickCollisions(ball))
      {
         m_brickSound->play();
      }
      const auto result = m_board.doWallCollisions(ball, paddle);
      if (result == Walls::OutsideBoard)
      {
         // TODO: handle outside, show game over?
         m_ball->setVelocity(Vector2f::Zero);
         positionBallAbovePaddle();
      }
      else if (result == Walls::Wall)
      {
         m_paddleSound->play();
      }


      // If ball has not been released from paddle yet, set ball position above paddle
      if (ball.isMoving() == false)
      {
         positionBallAbovePaddle();
      }

      if (ball.isMoving() && m_paddleCooldown <= 0 && m_paddle->isColliding(ball))
      {
         m_paddle->doBallCollision(ball);
         m_paddleSound->play();
         m_paddleCooldown = GameConfig::PaddleCooldown;
      }

      if (m_paddleCooldown > 0)
      {
         m_paddleCooldown -= deltaTime;
         //cout << m_paddleCooldown << "\n";
      }
   }

   void MainScene::draw(GraphicsSystem& graphics)
   {
      m_board.draw(graphics);
      for (auto entity : m_allEntities)
      {
         entity->draw(graphics);
      }
   }

   void MainScene::positionBallAbovePaddle() const
   {
      m_ball->setPosition(m_paddle->getPosition() + Vector2f(GameConfig::PaddleSize.x / 2.f, -float(GameConfig::BallDiameter)));
      
   }
}


