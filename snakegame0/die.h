#pragma once
#include "gamemanager.h"

class Die : public PhaseInterface {
public:
    Die();
    ~Die();

    void HandleEvents() override;
    void Update() override;
    virtual void Render() override;

private:
    //배경 이미지
    SDL_Texture* m_texture_die;
    SDL_Rect m_source_rect_die;
    SDL_Rect m_dest_rect_die;

};