#include "MainScene.h"
#include "Engine.h"


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
         }
      }
   }
   

   void MainScene::update(const float& deltaTime)
   {
      m_board.update(*m_ball, deltaTime);

      for (auto entity : m_allEntities)
      {
         entity->update(deltaTime);
      }
      
      // If ball has not been released from paddle yet, set ball position above paddle
      if (m_ball->getVelocity().length() <= 0)
      {
         positionBallAbovePaddle();
      }

      // TODO: fix proper paddle collision 
      //m_paddle->doBallCollision(*m_ball);
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


