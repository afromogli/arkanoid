#include "GraphicsSystem.h"

#include <iostream>
#include <assert.h>
#include <SDL2\SDL.h>
#include <SDL2/SDL_ttf.h>

namespace Arkanoid {
   GraphicsSystem::GraphicsSystem(const int& xWinPosition, const int& yWinPosition, const int& width, const int& height)
   {
      this->m_windowRect = { xWinPosition, yWinPosition, width, height };

      assert(this->initEverything());
   }

   GraphicsSystem::~GraphicsSystem()
   {
      TTF_Quit();
      SDL_DestroyRenderer(m_renderer);
      SDL_DestroyWindow(m_window);
      SDL_Quit();
   }

   void GraphicsSystem::startFrame() const
   {
      // Clear the window and make it all black
      SDL_SetRenderDrawColor(this->m_renderer, 0x00, 0x00, 0x00, 0x00);
      SDL_RenderClear(this->m_renderer);
   }

   void GraphicsSystem::endFrame() const
   {
      // Render the changes above
      SDL_RenderPresent(this->m_renderer);
   }

   bool GraphicsSystem::initEverything()
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

   bool GraphicsSystem::initSDL()
   {
      if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
      {
         std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
         return false;
      }

      return true;
   }

   bool GraphicsSystem::createWindow()
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

   bool GraphicsSystem::createRenderer()
   {
      this->m_renderer = SDL_CreateRenderer(this->m_window, -1, 0);

      if (this->m_renderer == nullptr)
      {
         std::cout << "Failed to create renderer : " << SDL_GetError();
         return false;
      }

      return true;
   }

   void GraphicsSystem::setupRenderer() const
   {
      TTF_Init();

      // Set size of renderer to the same as window
      SDL_RenderSetLogicalSize(this->m_renderer, this->m_windowRect.w, this->m_windowRect.h);

      // Set color of renderer to red
      SDL_SetRenderDrawColor(this->m_renderer, 0, 0, 0, 255);
   }

   SDL_Renderer * GraphicsSystem::getRenderer() const
   {
      return m_renderer;
   }

   SDL_Texture* GraphicsSystem::loadTexture(const std::string &str) const
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
}