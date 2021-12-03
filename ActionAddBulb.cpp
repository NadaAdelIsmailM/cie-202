#include "ActionAddBulb.h"
#include "ApplicationManager.h"
#include "Bulb.h"
ActionAddBulb::ActionAddBulb(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBulb::~ActionAddBulb(void)
{
}

void ActionAddBulb::Execute()
{

	UI* pUI = pManager->GetUI();


	pUI->PrintMsg("Adding a new bulb: Click anywhere to add");


	pUI->GetPointClicked(Cx, Cy);


	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Bulb* pR = new Bulb(pGInfo);
	pManager->AddComponent(pR);
}

void ActionAddBulb::Undo()
{}

void ActionAddBulb::Redo()
{}

