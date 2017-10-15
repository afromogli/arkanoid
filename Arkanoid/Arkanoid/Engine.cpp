#include "Engine.h"
#include "GameConfig.h"

#include "Scene.h"
#include <random>
#include <SDL2/SDL.h>

namespace Arkanoid {
   
   shared_ptr<EntityFactory> Engine::EntityFactoryInstance = shared_ptr<EntityFactory>(nullptr);
   shared_ptr<Engine> Engine::s_instance = shared_ptr<Engine>(nullptr);
   
   shared_ptr<Engine> Engine::getInstance()
   {
      if (s_instance == nullptr)
      {
         s_instance = shared_ptr<Engine>(new Engine());
      }
      return s_instance;
   }

   Engine::Engine() : m_graphics{ Graphics(int(GameConfig::WinInitPos.x), int(GameConfig::WinInitPos.y), int(GameConfig::WinSize.x), int(GameConfig::WinSize.y)) }, 
      m_currentScene{ shared_ptr<Scene>(nullptr) }
   {
      if (EntityFactoryInstance == nullptr) {
         EntityFactoryInstance = std::make_unique<EntityFactory>(m_graphics);
      }
      if (m_audioLoader.init() == false)
      {
         throw exception("Could not initialize audio.");
      }
   }

   void Engine::run()
   {
      bool runApplication = true;
      Uint64 previous = SDL_GetPerformanceCounter();
      Uint64 lag = 0;
      while (runApplication)
      {
         const Uint64 current = SDL_GetPerformanceCounter();
         // Deltatime in milliseconds
         const Uint64 elapsed = (((current - previous) * 1000 / SDL_GetPerformanceFrequency()));
         previous = current;
         lag += elapsed;

         SDL_Event events;
         while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT)
            {
               runApplication = false;
            }               
         }

         SDL_PumpEvents();
         const Uint8 *state = const_cast <Uint8*>(SDL_GetKeyboardState(nullptr));
         if (runApplication)
         {
            runApplication = state[SDL_SCANCODE_ESCAPE] == 0;
         }
         m_currentScene->handleInput(state);
         // Update physics using a fixed time step
         // If there is lag, allow physics to update a number of iterations
         while (lag >= GameConfig::MsPerUpdate)
         {
            m_currentScene->update(GameConfig::MsPerUpdate);
            lag -= static_cast<Uint64>(GameConfig::MsPerUpdate);
         }
         
         m_graphics.startFrame();
         m_currentScene->draw(m_graphics);
         m_graphics.endFrame();

         // Add a 16msec delay to make our game run at ~60 fps
         SDL_Delay(16);
      }
   }

   void Engine::setScene(const shared_ptr<Scene> newScene)
   {
      this->m_currentScene = newScene;
   }
}

