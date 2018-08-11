#include <SDL2/SDL_mixer.h>

namespace Tehsis {
  class Sound {
  public:
    Sound();
    ~Sound();
    void Play();
    void Stop();
    void Pause();
    void Resume();
  };
};