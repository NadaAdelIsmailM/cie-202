#include "Loadcircuit.h"
#include"../ApplicationManager.h"



Loadcircuit::Loadcircuit(ApplicationManager* pApp) :Action(pApp) {
	

}

Loadcircuit::~Load(void){}

void Loadcircuit::Execute() {

	UI* pUI = pManager->GetUI();
	pManager->Loadcircuit(myfile, pUI->GetSrting("Name of file .txt:");
}

void Loadcircuit::Undo() {}
void Loadcircuit::Redo() {}
