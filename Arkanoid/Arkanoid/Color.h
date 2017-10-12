#pragma once

namespace Arkanoid
{
   class Color
   {
   public:
      unsigned _int8 R;
      unsigned _int8 G;
      unsigned _int8 B;
      unsigned _int8 A;

      constexpr Color() : R{ 0 }, G{ 0 }, B{ 0 }, A{ 0 }
      {
      }

      constexpr Color(const Color& col) : R{ col.R }, G{ col.G }, B{ col.B }, A{ col.A }
      {
      }

      constexpr Color(const unsigned _int8 r, const unsigned _int8 g, const unsigned _int8 b, const unsigned _int8 a) : R{ r }, G{ g }, B{ b }, A{ a }
      {
      }

      constexpr Color(const unsigned _int8 r, const unsigned _int8 g, const unsigned _int8 b) : R{ r }, G{ g }, B{ b }, A{ 255 }
      {
      }
   };

   namespace Colors
   {
      static constexpr Color MakeRGB(const unsigned _int8 r, const unsigned _int8 g, const unsigned _int8 b, const unsigned _int8 a)
      {
         return Color(r, g, b, a);
      }

      static constexpr Color White = MakeRGB(255, 255, 255, 255);
      static constexpr Color DarkGrey = MakeRGB(169, 169, 169, 255);
      static constexpr Color DarkBlue = MakeRGB(0, 0, 139, 255);
   }
}
