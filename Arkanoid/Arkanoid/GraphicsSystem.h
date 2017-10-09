#pragma once

#include <vector>
#include <SDL2\SDL.h>

using namespace std;

namespace Arkanoid {
   class GraphicsSystem {
   public:
      GraphicsSystem(const int& xWinPosition, const int& yWinPosition, const int& width, const int& height);
      ~GraphicsSystem();

      void startFrame() const;
      void endFrame() const;

      SDL_Renderer* getRenderer() const;

      SDL_Texture* loadTexture(const std::string &str) const;
   
   private:
      SDL_Window* m_window;
      SDL_Renderer* m_renderer;
      SDL_Rect m_windowRect;
      
      bool initEverything();
      static bool initSDL();
      bool createWindow();
      bool createRenderer();
      void setupRenderer() const;      
   };

}

