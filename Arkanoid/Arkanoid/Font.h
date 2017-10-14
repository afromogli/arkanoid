#pragma once
#include <string>
#include <SDL2/SDL_ttf.h>

namespace Arkanoid
{
   class Font
   {
   public:
      Font(std::string fontFilePath, const int pointSize);
      ~Font();

      TTF_Font* get() const;
   private:
      TTF_Font *m_font;
   };
}
