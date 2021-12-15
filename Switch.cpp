#include "Switch.h"

Switch::Switch(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass switch drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo); //update to draw switch
	pUI->PrintMsg("Label:");

	string label = pUI->GetSrting();
	pUI->PrintMsg("Value:");
	string value = pUI->GetSrting();
}

void Switch::Operate()
{
}
void Switch::loadcircuit() {
	
}