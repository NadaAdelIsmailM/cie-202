#pragma once
#include "Component.h"

class fuse :public Component
{
public:
	fuse(GraphicsInfo* r_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void loadcircuit(int value, string files_name);
};
