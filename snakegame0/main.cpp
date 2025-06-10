#include <windows.h>
#include "gamemanager.h"
#include "intro.h"
#include "stage1.h"
#include "stage2.h"
#include "ending.h"
#include "die.h"

bool g_flag_running = true;
Uint32 g_last_time_ms;
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;

int g_current_game_phase = 0;


int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	//오디오
	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) == -1) {
		std::cout << "Mix_OpenAudio: %s\n" << Mix_GetError() << std::endl;
		exit(2);
	}


	//윈도우
	g_window = SDL_CreateWindow("Snake_Game", 100, 50, 1024, 800, SDL_WINDOW_SHOWN);
	if (g_window == nullptr) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(1);
	}

	//렌더러
	g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
	if (g_renderer == nullptr) {
		std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(g_window);
		SDL_Quit();
		exit(1);
	}

	InitGame();

	//동적할당
	PhaseInterface* game_phases[5];
	game_phases[PHASE_INTRO] = new Intro; 
	game_phases[PHASE_STAGE1] = new Stage1;
	game_phases[PHASE_STAGE2] = new Stage2;
	game_phases[PHASE_ENDING] = new Ending;
	game_phases[PHASE_DIE] = new Die;

	g_current_game_phase = PHASE_INTRO;
	g_last_time_ms = SDL_GetTicks();

	while (g_flag_running) {
		Uint32 cur_time_ms = SDL_GetTicks();

		if (cur_time_ms - g_last_time_ms < 33)
			continue;

		game_phases[g_current_game_phase]->HandleEvents();
		game_phases[g_current_game_phase]->Update();
		game_phases[g_current_game_phase]->Render();

		SDL_Delay(30);
		g_last_time_ms = cur_time_ms;
	}

	ClearGame();

	//동적할당 삭제
	for (int i = 0; i < 5; i++) {
		delete game_phases[i];
	}

	Mix_CloseAudio();
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	TTF_Quit();
	SDL_Quit();

	return 0;
}