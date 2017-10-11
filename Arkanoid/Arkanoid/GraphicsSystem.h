#pragma once

#include <SDL2/SDL.h>
#include "Vector2.h"
#include "Color.h"
#include "Rect2d.h"

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

      void drawFilledCircle(const Vector2f position, const int diameter, const Color color) const;
      void drawFilledRoundedBox(const Rect2D rect, const int borderRadius, const Color color) const;
      void drawFilledBox(const Rect2D rect, const Color color) const;

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

