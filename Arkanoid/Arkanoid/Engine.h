#pragma once

#include <memory>

#include "Graphics.h"
#include "EntityFactory.h"
#include "Scene.h"
#include "AudioLoader.h"

using namespace std;


namespace Arkanoid {
   

   class Engine { 
   public:
      Engine();
      void run();
      void setScene(shared_ptr<Scene> newScene);

      static shared_ptr<EntityFactory> entityFactoryInstance;

      inline Graphics& getGraphics() {
         return m_graphicsSystem;
      }

      inline AudioLoader& getAudioLoader() {
         return m_audioLoader;
      }
   private:
      Graphics m_graphicsSystem;
      AudioLoader m_audioLoader;
      shared_ptr<Scene> m_currentScene;
   };
}

