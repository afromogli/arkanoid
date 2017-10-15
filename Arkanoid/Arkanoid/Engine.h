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
      void run();
      void setScene(shared_ptr<Scene> newScene);

      static shared_ptr<EntityFactory> EntityFactoryInstance;

      Graphics& getGraphics() {
         return m_graphics;
      }

      AudioLoader& getAudioLoader() {
         return m_audioLoader;
      }

      static shared_ptr<Engine> getInstance();
   private:
      Engine();

      static shared_ptr<Engine> s_instance;
      Graphics m_graphics;
      AudioLoader m_audioLoader;
      shared_ptr<Scene> m_currentScene;
   };
}

