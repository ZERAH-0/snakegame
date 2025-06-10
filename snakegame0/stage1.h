#pragma once
#include "gamemanager.h"

class Stage1 : public PhaseInterface {
public:
	Stage1();
	~Stage1();

	virtual void HandleEvents() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	//배경 이미지
	SDL_Texture* m_bg_texture_stage1;
	SDL_Rect m_bg_source_rect_stage1;
	SDL_Rect m_bg_dest_rect_stage1;
};