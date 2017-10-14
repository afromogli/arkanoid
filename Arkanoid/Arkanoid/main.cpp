#include <SDL2/SDL.h>

#include "Engine.h"
#include "MainScene.h"
#include "StartScene.h"

using namespace Arkanoid;


int main(int argc, char* args[])
{
   auto engine = Engine::getInstance();
   const auto startScene = std::make_shared<StartScene>(engine->getGraphics());
   engine->setScene(startScene);
   engine->run();
   return 0;
}