#include "MainScene.h"
#include "Engine.h"
#include "GameConfig.h"
#include <math.h>
#include <iostream>
#include <SDL2_gfxPrimitives.h>
#include <random>
#include "xorshift.h"

namespace Arkanoid
{
   MainScene::MainScene(GraphicsSystem& graphics, AudioSystem& audioSystem) : m_graphics{ graphics }, m_audioSystem{audioSystem}
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
      for (auto entity : m_allEntities)
      {
         entity->update(deltaTime);
      }
   }

   void MainScene::draw(GraphicsSystem& graphics)
   {
      for (auto entity : m_allEntities)
      {
         entity->draw(graphics);
      }
   }
}


