#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "Engine.h"
#include "MainScene.h"

using namespace Arkanoid;


int main(int argc, char* args[])
{   
   unique_ptr<Engine> engine = unique_ptr<Engine>(new Engine());
   shared_ptr<MainScene> mainScene = shared_ptr<MainScene>(new MainScene(engine->getGraphics(), engine->getAudioSystem()));
   engine->setScene(mainScene);
   engine->run();

   return 0;
}