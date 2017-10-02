#pragma once

#include <memory>

#include "GraphicsSystem.h"
#include "EntityFactory.h"
#include "Scene.h"
#include "AudioSystem.h"

using namespace std;


namespace Arkanoid {
   

   class Engine { 
   public:
      Engine();
      void run();
      void setScene(shared_ptr<Scene> newScene);

      static shared_ptr<EntityFactory> entityFactoryInstance;

      inline GraphicsSystem& getGraphics() {
         return m_graphicsSystem;
      }

      inline AudioSystem& getAudioSystem() {
         return m_audioSystem;
      }
   private:
      GraphicsSystem m_graphicsSystem;
      AudioSystem m_audioSystem;
      shared_ptr<Scene> m_currentScene;
   };
}

