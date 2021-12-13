#include "Ground.h"

Ground::Ground(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Ground::Draw(UI* pUI)
{
	pUI->DrawGround(*m_pGfxInfo);

}

void Ground::Operate()
{

}
