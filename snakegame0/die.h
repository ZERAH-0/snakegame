#pragma once
#include "gamemanager.h"

class Die : public PhaseInterface {
public:
	Die();
	~Die();

	virtual void HandleEvents() override;
	virtual void Update() override;
	virtual void Render() override;

private:

};