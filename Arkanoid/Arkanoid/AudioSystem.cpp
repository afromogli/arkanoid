#include "AudioSystem.h"
#include <SDL2\SDL.h>
#include <SDL_mixer.h>

namespace Arkanoid 
{
   void AudioClip::play()
   {
      Mix_PlayChannel(-1, m_mixChunk, 0);
   }

   void AudioClip::load(const std::string filePath)
   {
      m_mixChunk = Mix_LoadWAV(filePath.c_str());
   }
   void AudioClip::freeMem()
   {
      Mix_FreeChunk(m_mixChunk);
   }

   AudioSystem::~AudioSystem()
   {
      for (auto clip : m_clips)
      {
         clip->freeMem();
      }
   }

   bool AudioSystem::init()
   {
      //Initialize SDL_mixer
      if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
      {
         return false;
      }
      return true;
   }

   std::shared_ptr<AudioClip> AudioSystem::createAndLoadAudioClip(const std::string filePath)
   {
      std::shared_ptr<AudioClip> newClip = std::shared_ptr<AudioClip>(new AudioClip());
      newClip->load(filePath);
      m_clips.push_back(newClip);

      return newClip;
   }

  
}