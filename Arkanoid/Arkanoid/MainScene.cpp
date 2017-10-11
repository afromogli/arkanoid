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
      respawnBall();

      m_allEntities.push_back(m_paddle);
      m_allEntities.push_back(m_ball);
   }

   MainScene::~MainScene()
   {

   }

   void MainScene::handleInput(const Uint8 *state)
   {
      /*if (state[SDL_SCANCODE_DOWN] && state[SDL_SCANCODE_UP])
      {
         setPaddleVelocity(m_rightPaddle, 0);
      }*/

   }

   

   void MainScene::update(const float& deltaTime)
   {
      m_board.update(deltaTime);
      for (auto entity : m_allEntities)
      {
         entity->update(deltaTime);
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

   void MainScene::respawnBall() const
   {
      m_ball->setPosition(m_paddle->getPosition() + Vector2f(GameConfig::PaddleSize.x / 2.f, -float(GameConfig::BallDiameter)));
   }
}


