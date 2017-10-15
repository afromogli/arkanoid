#include "MainScene.h"
#include "Engine.h"
#include <iostream>
#include <SDL2/SDL.h>

namespace Arkanoid
{
   MainScene::MainScene(Graphics& graphics, AudioLoader& audioSystem) :
      m_board{ GameConfig::BoardUpperLeftPos },
      m_graphics{ graphics },
      m_audioSystem{ audioSystem },
      m_font("Fonts\\iomanoid.ttf", 100),
      m_winText("You win!", Colors::LawnGreen, Vector2f(GameConfig::WinSize.x / 4, GameConfig::WinSize.y / 2 - 100), 500, 100, m_font, graphics),
      m_gameoverText("Game Over", Colors::Red, Vector2f(GameConfig::WinSize.x / 4, GameConfig::WinSize.y / 2 - 100), 500, 100, m_font, graphics),
      m_instructionsText("Press enter to continue..", Colors::White, Vector2f(GameConfig::WinSize.x / 4 + 100, GameConfig::WinSize.y / 2), 300, 60, m_font, graphics)
   {
      m_paddle = std::dynamic_pointer_cast<EPaddle>(Engine::EntityFactoryInstance->createEntity(EntityType::Paddle));
      m_ball = std::dynamic_pointer_cast<EBall>(Engine::EntityFactoryInstance->createEntity(EntityType::Ball));

      m_paddle->setPosition(GameConfig::InitialPlayerPaddlePosition);
      positionBallAbovePaddle();

      m_allEntities.push_back(m_paddle);
      m_allEntities.push_back(m_ball);

      m_brickSound = audioSystem.createAndLoadAudioClip("Sounds\\arkbrick.wav");
      m_paddleSound = audioSystem.createAndLoadAudioClip("Sounds\\arkpad.wav");
      m_winSound = audioSystem.createAndLoadAudioClip("Sounds\\win.wav");
      m_gameoverSound = audioSystem.createAndLoadAudioClip("Sounds\\gameover.wav");
   }

   MainScene::~MainScene()
   {
   }

   void MainScene::handleInput(const Uint8 *state)
   {
      switch (m_currentState)
      {
      case Playing:
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
         break;
      case GameOver:
      case Win:
         if (state[SDL_SCANCODE_RETURN])
         {
            m_currentState = Playing;
            m_winSound->stop();
            m_gameoverSound->stop();
            m_board.reset();
         }
         break;
      default:;
      }     
   }

   void MainScene::update(const float& deltaTime)
   {
      switch (m_currentState)
      {
      case Playing:
         updatePlayingState(deltaTime);
         break;
      case GameOver:
         m_ball->setVelocity(Vector2f::Zero);
         positionBallAbovePaddle();
         break;
      default:;
      }     
   }

   void MainScene::draw(Graphics& graphics)
   {
      m_board.draw(graphics);
      for (auto entity : m_allEntities)
      {
         entity->draw(graphics);
      }

      if (m_currentState == Win)
      {
         m_winText.draw(graphics);
         m_instructionsText.draw(graphics);
      } 
      else if (m_currentState == GameOver)
      {
         m_gameoverText.draw(graphics);
         m_instructionsText.draw(graphics);
      }
   }

   void MainScene::updatePlayingState(const float deltaTime)
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
         if (m_board.hasAnyAliveBricks() == false)
         {
            m_currentState = Win;
            m_winSound->play();
         }
      }
      const auto result = m_board.doWallCollisions(ball, paddle);
      if (result == Walls::OutsideBoard)
      {
         m_currentState = GameOver;
         m_gameoverSound->play();
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
      else if (m_paddleCooldown <= 0 && m_paddle->isColliding(ball))
      {
         m_paddle->doBallCollision(ball);
         m_paddleSound->play();
         m_paddleCooldown = GameConfig::PaddleCooldown;
      }

      if (m_paddleCooldown > 0)
      {
         m_paddleCooldown -= deltaTime;
      }
   }

   void MainScene::positionBallAbovePaddle() const
   {
      m_ball->setPosition(m_paddle->getPosition() + Vector2f(GameConfig::PaddleSize.x / 2.f, -float(GameConfig::BallDiameter)));

   }
}


