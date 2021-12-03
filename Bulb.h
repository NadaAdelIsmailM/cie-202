#pragma once
#include".\Components\Component.h"

class Bulb :public Component
{
public:
	Bulb(GraphicsInfo* r_GfxInfo);
	virtual void Operate();
	virtual void Draw(UI*);

};
