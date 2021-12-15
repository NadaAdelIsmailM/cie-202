#include "ApplicationManager.h"
#include "Actions/ActionAddSwitch.h"
#include "Actions\ActionAddRes.h"
#include "Actions/ActionAddfuse.h
#include"ActionAddBuzz.h"
#include"ActionAddBulb.h "
#include"ActionAddConnec.h "
#include"Actions/ActionAddBattery.h"
#include "Actions/ActionSimWindow.h"
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
		case ADD_SWITCH:
			pAct= new ActionAddSwitch(this);
			break;
		case ADD_GRND:
			pAct = new ActionAddGround(this);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuzz(this);
			break;
		case ADD_FUSE:
			pAct = new ActionAddfuse(this);
			break;
		case ADD_CONNECTION:
			pAct = new ActionAddConnec(this);
			break;
                case SIM_MODE:
			pAct = new ActionSimWindow(this);
			break;
                case LOAD:
			pAct = new Loadcircuit(this);
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
void ApplicationManager:: Load(ifstream& myfile, string files_name){
	ifstream myfile;
	myfile.open(files_name);
	if (!file.fail()){
	int x;
	myfile >> x;
	Action* pAct = nullptr;
	string type, id, label;
	int value, topx, topy;
	for (int i = 1; i <= x; i++) {
		
		myfile >> type >> id >> label >> value >> topx >> topy;
		GI= new GraphicsInfo(2);
		GI->PointsList[0].x = graphicInfoX;
		GI->PointsList[0].y = graphicInfoY;
		GI->PointsList[1].x = graphicInfoX + pUI->getCompWidth();;
		GI->PointsList[1].y = graphicInfoY + pUI->getCompHeight();
		{
			//assign the coordinates to the component which will be loaded on the interface
		

						if (type == "RES") {

							/*GraphicsInfo* PgInfo = new GraphicsInfo(2);  //pointer to graphics info
							PgInfo->PointsList[i].x = topx; //load coordinates
							PgInfo->PointsList[i].y = topy;*/
							Resistor* cmp = new Resistor(GI);
							cmp->Load(value, label);
							AddComponent(comp);
						}
						else if (type == "SWT")
						{
							Switchr* cmp = new Switch(GI);
							cmp->Load(value, label);
							AddComponent(comp);
						}
						else if (type == "FUSE") {
							fuse* cmp = new fuse(GI);
							cmp->Load(value, label);
							AddComponent(comp);
						}
						else if (type == "BAT") {
							/*GraphicsInfo* PgInfo = new GraphicsInfo(2);  //pointer to graphics info
							PgInfo->PointsList[i].x = topx; //load coordinates
							PgInfo->PointsList[i].y = topy;
							Component* cmp = new Battery(PgInfo);
							cmp->loadcircuit();*/
							Battery* cmp = new Battery(GI);
							cmp->Load(value, label);
							AddComponent(comp);
							
						}
						else if (type == "BLB") {
							Bulb* cmp = new Bulb(GI);
							cmp->Load(value, label);
							AddComponent(comp);
							
						}
						else if (type == "GND") {
							Ground* cmp = new Ground(GI);
							cmp->Load(value, label);
							AddComponent(comp);
							
						}
			if(i==x&& type=="Connections"){
				int comp1, comp2, graphicspoint;
				myfile >> num;
				while (myfile >> comp1) {
					myfile >> comp2;

					myfile >> graphicspoint;
					GI = new GraphicsInfo(2);
					GI->PointsList[0].x = graphicspoint;
					myfile >> graphicspoint;
					GI->PointsList[0].y = graphicspoint;
					myfile >> graphicspoint;
					GI->PointsList[1].x = graphicspoint;
					myfile >> graphicspoint;
					GI->PointsList[1].y = graphicspoint;
					Connection* C = new Connection(GI);
					C->Load(CompList[comp1 - 1], CompList[comp2 - 1]);
					AddConnection(C);
				}



			}

		}



	}
	else
		pUI->PrintMsg("File open failure! ");
				}
			}
		
 myfile.close();}

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
