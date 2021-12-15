#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo,bool IsOn) : Component(r_GfxInfo)
{
	this->IsOn = IsOn;
}

void Bulb::Draw(UI* pUI)
{
	pUI->DrawBulb(*m_pGfxInfo,IsSelected,IsOn);

}

void Bulb::Operate()
{

}
void Switch::loadcircuit() {

}
