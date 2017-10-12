#pragma once

#include "Scene.h"
#include "AudioSystem.h"
#include "Entity.h"
#include "Board.h"
#include "EPaddle.h"

using namespace std;

namespace Arkanoid 
{
   class MainScene : public Scene
   {
   public:
      MainScene(GraphicsSystem& graphics, AudioSystem& audioSystem);
      ~MainScene();

      void handleInput(const Uint8 *keyboardState) override;
      void update(const float& deltaTime) override;
      void draw(GraphicsSystem& graphics) override;
   
   private:
      vector<shared_ptr<Entity>> m_allEntities;
      Board m_board;
      shared_ptr<EPaddle> m_paddle;
      shared_ptr<EBall> m_ball;

      float m_paddleCooldown; // Millisecs, for collisions

      GraphicsSystem& m_graphics;
      AudioSystem& m_audioSystem;

      void positionBallAbovePaddle() const;
   };
}

