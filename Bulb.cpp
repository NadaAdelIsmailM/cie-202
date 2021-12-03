#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo) : Component(r_GfxInfo)
{}

void Bulb::Draw(UI* pUI)
{
	pUI->DrawBulb(*m_pGfxInfo);

}

void Bulb::Operate()
{

}