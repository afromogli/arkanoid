#include "StartScene.h"
#include "GameConfig.h"
#include "Engine.h"
#include "MainScene.h"

namespace Arkanoid
{
   StartScene::StartScene(Graphics& graphics) : m_font("Fonts\\iomanoid.ttf", 100),
      m_arkanoidText("Arkanoid", Colors::DarkBlue, Vector2f(GameConfig::WinSize.x/4, GameConfig::WinSize.y/2 - 100), 500, 100, m_font, graphics),
      m_instructionsText("Press enter to start", Colors::White, Vector2f(GameConfig::WinSize.x / 4 + 100, GameConfig::WinSize.y / 2), 300, 60, m_font, graphics)
   {
   }

   void StartScene::handleInput(const Uint8* state)
   {
      if (state[SDL_SCANCODE_RETURN])
      {
         auto engine = Engine::getInstance();
         const auto mainScene = std::make_shared<MainScene>(engine->getGraphics(), engine->getAudioLoader());
         engine->setScene(mainScene);
      }
   }

   void StartScene::update(const float& deltaTime)
   {
   }

   void StartScene::draw(Graphics& graphics)
   {
      m_arkanoidText.draw(graphics);
      m_instructionsText.draw(graphics);
   }
}
