#include "Text.h"
#include <SDL2/SDL_ttf.h>

namespace Arkanoid
{
   Text::Text(const string text, const Color color, const Vector2f position, const int fontSizeX,
      const int fontSizeY, Font& font, Graphics& graphics) : m_texture{ nullptr }, m_font{ font }, m_graphics{ graphics }
   {
      m_text = text;
      m_color = color;
      m_rect.x = int(position.x);
      m_rect.y = int(position.y);
      m_rect.w = fontSizeX;
      m_rect.h = fontSizeY;
      m_graphics = graphics;

      m_texture = createTexture(graphics, m_font, m_text, m_color);
   }

   Text::~Text()
   {
      SDL_DestroyTexture(m_texture);
   }

   void Text::update(const float& deltaTime)
   {
   }

   void Text::draw(Graphics& graphics)
   {
      SDL_RenderCopy(graphics.getRenderer(), m_texture, nullptr, &m_rect);
   }

   SDL_Texture* Text::createTexture(Graphics& graphics, const Font& font, const string text, const Color color)
   {
      SDL_Surface *surface = TTF_RenderText_Solid(font.get(), text.c_str(), { color.R, color.G, color.B, color.A });
      SDL_Texture* texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), surface);
      SDL_FreeSurface(surface);
      return texture;
   }
}
