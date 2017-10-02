#pragma once

#include <stdexcept>
#include <string>

namespace Arkanoid {
   class NotSupportedException : public std::logic_error
   {
   public:
      NotSupportedException(std::string message) : std::logic_error(message) { };
   };
}
