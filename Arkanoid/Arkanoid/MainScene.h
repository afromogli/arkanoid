#pragma once

#include <memory>
#include "Scene.h"
#include "AudioSystem.h"
#include "Entity.h"

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
      vector<shared_ptr<Entity>> m_allEntities;      
      GraphicsSystem& m_graphics;
      AudioSystem& m_audioSystem;
   };
}

