#pragma once
#include "gamemanager.h"

class Intro : public PhaseInterface {
public:
    Intro();
    ~Intro();

    void HandleEvents() override;
    void Update() override;
    void Render() override;

private:
    //배경 이미지
    SDL_Texture* m_bg_texture_intro;
    SDL_Rect m_bg_source_rect_intro;
    SDL_Rect m_bg_dest_rect_intro;

	//버튼
	SDL_Texture* m_button_start;
	SDL_Rect m_button_start_source;
	SDL_Rect m_button_start_rect;

	SDL_Texture* m_button_exit;
	SDL_Rect m_button_exit_source;
	SDL_Rect m_button_exit_rect;

	//배경음
	Mix_Music* m_intro_mus;

	//효과음
	Mix_Chunk* click_button;
};