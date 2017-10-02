#include "GameConfig.h"

namespace Arkanoid
{
   Vector2f GameConfig::WinInitPos = Vector2f(900, 300);
   Vector2f GameConfig::WinSize = Vector2f(800, 600);


   Vector2f GameConfig::InitialPlayerPaddlePosition = Vector2f(GameConfig::WinSize.x - 20, GameConfig::WinSize.y / 2 - 5);
   Vector2f GameConfig::InitialCpuPaddlePosition = Vector2f(20, GameConfig::WinSize.y / 2 - 5);

   Vector2f GameConfig::PaddleSize = Vector2f(10, 60);
}