#include "gamemanager.h"
#include "ending.h"
#include <iostream>

Ending::Ending() {

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cout << "IMG_init failed: " << IMG_GetError() << std::endl;
		exit(1);
	}

	//배경 이미지 로드
	SDL_Surface* temp_surface = IMG_Load("Resource/ending.png");
	m_texture_ending = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(m_texture_ending, NULL, NULL, &m_source_rect_ending.w, &m_source_rect_ending.h);
	m_dest_rect_ending.x = m_source_rect_ending.x = 0;
	m_dest_rect_ending.y = m_source_rect_ending.y = 0;
	m_dest_rect_ending.w = m_source_rect_ending.w;
	m_dest_rect_ending.h = m_source_rect_ending.h;

	// std::cout 출력에 버퍼를 사용하여, 출력 속도가 느려지는 현상을 피한다.
	setvbuf(stdout, NULL, _IOLBF, 4096);

	// 표준출력 화면을 깨끗히 지운다.
	system("cls");
}


void Ending::Update() {

}

void Ending::Render() {
	SDL_RenderClear(g_renderer);
	//배경 이미지
	SDL_RenderCopy(g_renderer, m_texture_ending, &m_source_rect_ending, &m_dest_rect_ending);

	SDL_RenderPresent(g_renderer);
}

void Ending::HandleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			g_flag_running = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == 1) {
				int mouse_x = event.button.x;
				int mouse_y = event.button.y;

				g_current_game_phase = PHASE_INTRO;
			}
			break;
		default:
			break;
		}
	}
}

Ending::~Ending() {
	SDL_DestroyTexture(m_texture_ending);
	IMG_Quit();
}