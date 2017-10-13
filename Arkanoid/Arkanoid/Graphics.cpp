#include "Graphics.h"

#include <iostream>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2_gfxPrimitives.h>

namespace Arkanoid {
   Graphics::Graphics(const int& xWinPosition, const int& yWinPosition, const int& width, const int& height)
   {
      this->m_windowRect = { xWinPosition, yWinPosition, width, height };

      assert(this->initEverything());
   }

   Graphics::~Graphics()
   {
      TTF_Quit();
      SDL_DestroyRenderer(m_renderer);
      SDL_DestroyWindow(m_window);
      SDL_Quit();
   }

   void Graphics::startFrame() const
   {
      // Clear the window and make it all black
      SDL_SetRenderDrawColor(this->m_renderer, 0x00, 0x00, 0x00, 0x00);
      SDL_RenderClear(this->m_renderer);
   }

   void Graphics::endFrame() const
   {
      // Render the changes above
      SDL_RenderPresent(this->m_renderer);
   }

   bool Graphics::initEverything()
   {
      if (!initSDL())
         return false;

      if (!createWindow())
         return false;

      if (!createRenderer())
         return false;

      setupRenderer();

      return true;
   }

   bool Graphics::initSDL()
   {
      if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
      {
         std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
         return false;
      }

      return true;
   }

   bool Graphics::createWindow()
   {
      //window = SDL_CreateWindow( "Server", posX, posY, sizeX, sizeY, 0 );
      this->m_window = SDL_CreateWindow("Arkanoid", this->m_windowRect.x, this->m_windowRect.y, this->m_windowRect.w, this->m_windowRect.h, 0);

      if (this->m_window == nullptr)
      {
         std::cout << "Failed to create window : " << SDL_GetError();
         return false;
      }

      return true;
   }

   bool Graphics::createRenderer()
   {
      this->m_renderer = SDL_CreateRenderer(this->m_window, -1, 0);

      if (this->m_renderer == nullptr)
      {
         std::cout << "Failed to create renderer : " << SDL_GetError();
         return false;
      }

      return true;
   }

   void Graphics::setupRenderer() const
   {
      TTF_Init();

      // Set size of renderer to the same as window
      SDL_RenderSetLogicalSize(this->m_renderer, this->m_windowRect.w, this->m_windowRect.h);

      // Set color of renderer to red
      SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
   }

   SDL_Renderer * Graphics::getRenderer() const
   {
      return m_renderer;
   }

   SDL_Texture* Graphics::loadTexture(const std::string &str) const
   {
      // Load image as SDL_Surface
      SDL_Surface* surface = SDL_LoadBMP(str.c_str());

      // SDL_Surface is just the raw pixels
      // Convert it to a hardware-optimzed texture so we can render it
      SDL_Texture* texture = SDL_CreateTextureFromSurface(this->m_renderer, surface);

      // Don't need the orignal texture, release the memory
      SDL_FreeSurface(surface);

      return texture;
   }

   void Graphics::drawFilledCircle(const Vector2f position, const int diameter, const Color color) const
   {
      filledCircleRGBA(m_renderer, Sint16(position.x), Sint16(position.y), diameter, color.R, color.G, color.B, color.A);
   }

   void Graphics::drawFilledRoundedBox(const Rect2D rect, const int borderRadius, const Color color) const
   {
      roundedBoxRGBA(m_renderer, Sint16(rect.getPosition().x), Sint16(rect.getPosition().y), 
         Sint16(rect.getPosition().x + rect.getWidth()), Sint16(rect.getPosition().y + rect.getHeight()),
         borderRadius, color.R, color.G, color.B, color.A);
   }

   void Graphics::drawFilledBox(const Rect2D rect, const Color color) const
   {
      boxRGBA(m_renderer, Sint16(rect.getPosition().x), Sint16(rect.getPosition().y),
         Sint16(rect.getPosition().x + rect.getWidth()), Sint16(rect.getPosition().y + rect.getHeight()),
         color.R, color.G, color.B, color.A);
   }
}
