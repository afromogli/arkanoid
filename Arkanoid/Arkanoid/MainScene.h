#pragma once

#include "Scene.h"
#include "AudioLoader.h"
#include "Entity.h"
#include "Board.h"
#include "EPaddle.h"

using namespace std;

namespace Arkanoid 
{
   class MainScene : public Scene
   {
   public:
      MainScene(Graphics& graphics, AudioLoader& audioSystem);
      ~MainScene();

      void handleInput(const Uint8 *keyboardState) override;
      void update(const float& deltaTime) override;
      void draw(Graphics& graphics) override;
   
   private:
      vector<shared_ptr<Entity>> m_allEntities;
      shared_ptr<EPaddle> m_paddle;
      shared_ptr<EBall> m_ball;
      Board m_board;

      float m_paddleCooldown; // Millisecs, for collisions

      Graphics& m_graphics;
      AudioLoader& m_audioSystem;

      void positionBallAbovePaddle() const;

      shared_ptr<AudioClip> m_brickSound;
      shared_ptr<AudioClip> m_paddleSound;
   };
}

