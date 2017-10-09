#pragma once

#include <stdexcept>

namespace Arkanoid {
   class NotImplementedException : public logic_error
   {
   public:
      NotImplementedException() : logic_error("Function not yet implemented") { };
   };
}

