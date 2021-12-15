#pragma once
#include".\Components\Component.h"

class Bulb :public Component
{
	bool IsOn,IsSelected;
public:
	Bulb(GraphicsInfo* r_GfxInfo,bool IsOn);
	virtual void Operate();
	virtual void Draw(UI*);
	virtual void loadcircuit();

};
