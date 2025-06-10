#include "gamemanager.h"
#include "stage2.h"
#include <iostream>

Stage2::Stage2() {
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cout << "IMG_init failed: " << IMG_GetError() << std::endl;
		exit(1);
	}

	//배경 이미지 로드
	SDL_Surface* temp_surface = IMG_Load("Resource/stage2.png");
	m_bg_texture_stage2 = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(m_bg_texture_stage2, NULL, NULL, &m_bg_source_rect_stage2.w, &m_bg_source_rect_stage2.h);
	m_bg_dest_rect_stage2.x = m_bg_source_rect_stage2.x = 0;
	m_bg_dest_rect_stage2.y = m_bg_source_rect_stage2.y = 0;
	m_bg_dest_rect_stage2.w = m_bg_source_rect_stage2.w;
	m_bg_dest_rect_stage2.h = m_bg_source_rect_stage2.h;

	// std::cout 출력에 버퍼를 사용하여, 출력 속도가 느려지는 현상을 피한다.
	setvbuf(stdout, NULL, _IOLBF, 4096);

	// 표준출력 화면을 깨끗히 지운다.
	system("cls");
}

void Stage2::Update() {

}

void Stage2::Render() {
	SDL_RenderClear(g_renderer);
	//배경 이미지
	SDL_RenderCopy(g_renderer, m_bg_texture_stage2, &m_bg_source_rect_stage2, &m_bg_dest_rect_stage2); //배경 이미지 전체 그리기

	SDL_RenderPresent(g_renderer);
}

void Stage2::HandleEvents() {
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

				g_current_game_phase = PHASE_ENDING;
			}
			break;
		default:
			break;
		}
	}
}

Stage2::~Stage2() {
	SDL_DestroyTexture(m_bg_texture_stage2);
	IMG_Quit();
}
