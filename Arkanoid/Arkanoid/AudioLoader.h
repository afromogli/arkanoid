#pragma once

#include <vector>
#include <SDL_mixer.h>
#include <memory>

namespace Arkanoid
{
   class AudioClip
   {
   public:
      explicit AudioClip()
         : m_mixChunk(nullptr)
      {
      }

      void play();

      void load(const std::string filePath);
      void freeMem();

   private:
      Mix_Chunk *m_mixChunk;
   };

   class AudioLoader
   {
   public:
      ~AudioLoader();

      bool init();

      std::shared_ptr<AudioClip> createAndLoadAudioClip(const std::string filePath);


   private:
      std::vector<std::shared_ptr<AudioClip>> m_clips;
   };
}