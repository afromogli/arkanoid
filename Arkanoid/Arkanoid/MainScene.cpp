#include "MainScene.h"
#include "Engine.h"


namespace Arkanoid
{
   MainScene::MainScene(GraphicsSystem& graphics, AudioSystem& audioSystem) : 
      m_board{ GameConfig::BoardUpperLeftPos }, 
      m_graphics{ graphics }, 
      m_audioSystem{ audioSystem }
   {
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
   }

   void MainScene::draw(GraphicsSystem& graphics)
   {
      m_board.draw(graphics);
      /*for (auto obj : m_allEntities)
      {
         obj.draw(graphics);
      }*/
   }
}


