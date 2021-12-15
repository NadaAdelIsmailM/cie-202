#include "Loadcircuit.h"
#include"../ApplicationManager.h"



Loadcircuit::Loadcircuit(ApplicationManager* pApp) :Action(pApp) {
	

}



void Loadcircuit::Execute() {

	ifstream myfile;
	myfile.open("images\\Menu\\myfile.txt");
	int x;
	myfile >> x;
	pManager->loadcircuit();
}

void Loadcircuit::Undo() {}
void Loadcircuit::Redo() {}
