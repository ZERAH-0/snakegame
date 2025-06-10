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

};