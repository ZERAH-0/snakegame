#pragma once
#include "gamemanager.h"

class Stage2 : public PhaseInterface {
public:
    Stage2();
    ~Stage2();

    void HandleEvents() override;
    void Update() override;
    virtual void Render() override;

private:
    // 배경 이미지
    SDL_Texture* m_bg_texture_stage2;
    SDL_Rect m_bg_source_rect_stage2;
    SDL_Rect m_bg_dest_rect_stage2;
};