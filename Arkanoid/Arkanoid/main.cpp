#include <SDL2/SDL.h>

#include "Engine.h"
#include "MainScene.h"

using namespace Arkanoid;


int main(int argc, char* args[])
{   
   unique_ptr<Engine> engine = std::make_unique<Engine>();
   const shared_ptr<MainScene> mainScene = std::make_shared<MainScene>(engine->getGraphics(), engine->getAudioLoader());
   engine->setScene(mainScene);
   engine->run();

   return 0;
}