#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include"ActionAddBuzz.h"
#include"ActionAddBulb.h "
#include"ActionAddConnec.h "
#include"Actions/ActionAddBattery.h"
#include"Actions/ActionAddGround.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i < MaxCompCount; i++)
		ConnList[i] = nullptr;
	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
void ApplicationManager::AddConnection(Connection* pConn)
{
	ConnList[ConnCount++] = pConn;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		case ADD_LAMP:
			pAct = new ActionAddBulb(this);
			break;		
		case ADD_BATTERY:
			pAct = new ActionAddBattery(this);
			break;
		/*case ADD_SWITCH:
			pAct = new ActionAddSwitch(this);
			break;*/
		case ADD_GRND:
			pAct = new ActionAddGround(this);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuzz(this);
			break;
		/*case ADD_FUSE:
			pAct = new ActionAddfuse(this);
			break;*/
		case ADD_CONNECTION:
			pAct = new ActionAddConnec(this);
			break;



		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);
		for(int i = 0; i < ConnCount; i++)
			ConnList[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}


////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	for (int i = 0; i < ConnCount; i++)
		delete ConnList[i];
	delete pUI;
	
}

bool ApplicationManager::ValidConnectionPoint(int x, int y, const Component* c1)  {
	int c = 0;
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->IsInRegion(x, y)) {
			c1 = CompList[i];
			c++;
		}
	}
	if (c > 0)
		return true;	
	else
		return false;
	
	
}