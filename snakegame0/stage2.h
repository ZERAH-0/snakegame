#pragma once
#include "gamemanager.h"

class Stage2 : public PhaseInterface {
public:
	Stage2();
	~Stage2();

	virtual void HandleEvents() override;
	virtual void Update() override;
	virtual void Render() override;

private:

};