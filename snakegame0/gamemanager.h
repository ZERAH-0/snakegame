#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <atlstr.h>


void InitGame();
void ClearGame();

//게임 페이즈
const int PHASE_INTRO = 0;
const int PHASE_STAGE1 = 1;
const int PHASE_STAGE2 = 2;
const int PHASE_ENDING = 3;
const int PHASE_DIE = 4;

//현재 페이즈
extern int g_current_game_phase;

extern bool g_flag_running;
extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;

//배경음 제어
extern int g_last_music;

//효과음
extern Mix_Chunk* life_minus;

class PhaseInterface {
public:
    virtual ~PhaseInterface() {}
    virtual void HandleEvents() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};
