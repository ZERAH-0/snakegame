#pragma once
#include "gamemanager.h"

class Ending : public PhaseInterface {
public:
	Ending();
	~Ending();

	void HandleEvents() override;
	void Update() override;
	virtual void Render() override;

private:
	//배경 이미지
	SDL_Texture* m_texture_ending;
	SDL_Rect m_source_rect_ending;
	SDL_Rect m_dest_rect_ending;
};