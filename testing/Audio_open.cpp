#include <iostream>
#include <SDL2/SDL.h>

int main() {
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8* wavBuffer;

    if (SDL_LoadWAV("audio.wav", &wavSpec, &wavBuffer, &wavLength) == NULL) {
        std::cerr << "SDL_LoadWAV Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if (deviceId == 0) {
        std::cerr << "SDL_OpenAudioDevice Error: " << SDL_GetError() << std::endl;
        SDL_FreeWAV(wavBuffer);
        SDL_Quit();
        return 1;
    }

    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    if (success != 0) {
        std::cerr << "SDL_QueueAudio Error: " << SDL_GetError() << std::endl;
        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(wavBuffer);
        SDL_Quit();
        return 1;
    }

    SDL_PauseAudioDevice(deviceId, 0);

    SDL_Delay(3000);

    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();

    return 0;
}
