#include "Font.h"

namespace Arkanoid
{
   Font::Font(std::string fontFilePath, const int pointSize) : m_font{ nullptr }
   {
      m_font = TTF_OpenFont(fontFilePath.c_str(), pointSize);
      if (m_font == nullptr)
      {
         fprintf(stderr, "error: font not found\n");
         exit(EXIT_FAILURE);
      }
   }

   Font::~Font()
   {
      if (m_font != nullptr)
      {
         TTF_CloseFont(m_font);
      }
   }

   TTF_Font* Font::get() const
   {
      return m_font;
   }
}
