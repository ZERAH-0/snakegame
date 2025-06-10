#include "gamemanager.h"
#include "intro.h"
#include <iostream>


Intro::Intro() {
	
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cout << "IMG_init failed: " << IMG_GetError() << std::endl;
		exit(1);
	}

	//배경 이미지 로드
	SDL_Surface* temp_surface = IMG_Load("Resource/intro.png");
	m_bg_texture_intro = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(m_bg_texture_intro, NULL, NULL, &m_bg_source_rect_intro.w, &m_bg_source_rect_intro.h);
	m_bg_dest_rect_intro.x = m_bg_source_rect_intro.x = 0;
	m_bg_dest_rect_intro.y = m_bg_source_rect_intro.y = 0;
	m_bg_dest_rect_intro.w = m_bg_source_rect_intro.w;
	m_bg_dest_rect_intro.h = m_bg_source_rect_intro.h;

	//시작 버튼 이미지 로드 
	SDL_Surface* button_surface1 = IMG_Load("Resource/startB.png");
	m_button_start = SDL_CreateTextureFromSurface(g_renderer, button_surface1);
	SDL_FreeSurface(button_surface1);
	m_button_start_source = { 0,0,283,100 };
	m_button_start_rect = { 50,650,283,100 };

	//종료 버튼 이미지 로드
	SDL_Surface* button_surface2 = IMG_Load("Resource/quitB.png");
	m_button_exit = SDL_CreateTextureFromSurface(g_renderer, button_surface2);
	SDL_FreeSurface(button_surface2);
	m_button_exit_source = { 0,0,283,100 };
	m_button_exit_rect = { 700,650,283,100 };

	// std::cout 출력에 버퍼를 사용하여, 출력 속도가 느려지는 현상을 피한다.
	setvbuf(stdout, NULL, _IOLBF, 4096);

	// 표준출력 화면을 깨끗히 지운다.
	system("cls");
}

void Intro::Update() {

}

void Intro::Render() {
	SDL_RenderClear(g_renderer);

	//배경 이미지
	SDL_RenderCopy(g_renderer, m_bg_texture_intro, &m_bg_source_rect_intro, &m_bg_dest_rect_intro);

	//버튼
	SDL_RenderCopy(g_renderer, m_button_start, &m_button_start_source, &m_button_start_rect);
	SDL_RenderCopy(g_renderer, m_button_exit, &m_button_exit_source, &m_button_exit_rect);

	SDL_RenderPresent(g_renderer);
}

void Intro::HandleEvents() {
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

				SDL_Rect& b = m_button_start_rect;
				SDL_Rect& e = m_button_exit_rect;

				//버튼 클릭이 가능한 구역 설정
				if (mouse_x >= b.x && mouse_x < b.x + b.w && mouse_y >= b.y && mouse_y < b.y + b.h)
				{
					Mix_PlayChannel(-1, click_button, 0);
					g_current_game_phase = PHASE_STAGE1;
				}
				else if (mouse_x >= e.x && mouse_x < e.x + e.w && mouse_y >= e.y && mouse_y < e.y + e.h)
				{
					Mix_PlayChannel(-1, click_button, 0);
					g_flag_running = false;
				}
			}
			break;
		default:
			break;
		}
	} 
}


Intro::~Intro() {
	IMG_Quit();

	//이미지 해제
	SDL_DestroyTexture(m_bg_texture_intro);
	SDL_DestroyTexture(m_button_start);
	SDL_DestroyTexture(m_button_exit);
}