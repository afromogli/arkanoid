#pragma once

#include "Scene.h"
#include "AudioSystem.h"
#include "Entity.h"
#include "Board.h"

using namespace std;

namespace Arkanoid 
{
   class MainScene : public Scene
   {
   public:
      MainScene(GraphicsSystem& graphics, AudioSystem& audioSystem);
      ~MainScene();

      void handleInput(const Uint8 *keyboardState) override;
      void update(const float& deltaTime) override;
      void draw(GraphicsSystem& graphics) override;
   
   private:
      vector<Entity> m_allEntities;
      Board m_board;
      GraphicsSystem& m_graphics;
      AudioSystem& m_audioSystem;
   };
}

