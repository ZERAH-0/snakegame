#include "gamemanager.h"
#include "stage1.h"
#include <iostream>

Stage1::Stage1() {
	g_flag_running = true;

	//배경 이미지 로드
	SDL_Surface* temp_surface1 = IMG_Load("Resource/stage1.png");
	m_bg_texture_stage1 = SDL_CreateTextureFromSurface(g_renderer, temp_surface1);
	SDL_FreeSurface(temp_surface1);

	SDL_QueryTexture(m_bg_texture_stage1, NULL, NULL, &m_bg_source_rect_stage1.w, &m_bg_source_rect_stage1.h);
	m_bg_dest_rect_stage1.x = m_bg_source_rect_stage1.x = 0;
	m_bg_dest_rect_stage1.y = m_bg_source_rect_stage1.y = 0;
	m_bg_dest_rect_stage1.w = m_bg_source_rect_stage1.w;
	m_bg_dest_rect_stage1.h = m_bg_source_rect_stage1.h;

	// std::cout 출력에 버퍼를 사용하여, 출력 속도가 느려지는 현상을 피한다.
	setvbuf(stdout, NULL, _IOLBF, 4096);

	// 표준출력 화면을 깨끗히 지운다.
	system("cls");
}

void Stage1::Update() {

}

void Stage1::Render() {
	SDL_RenderClear(g_renderer);

	//배경이미지
	SDL_RenderCopy(g_renderer, m_bg_texture_stage1, &m_bg_source_rect_stage1, &m_bg_dest_rect_stage1);
	
	SDL_RenderPresent(g_renderer);
}

void Stage1::HandleEvents() {
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

				g_current_game_phase = PHASE_STAGE2;
			}
			break;
		default:
			break;
		}
	}
}

Stage1::~Stage1() {
	SDL_DestroyTexture(m_bg_texture_stage1);
	IMG_Quit();
}