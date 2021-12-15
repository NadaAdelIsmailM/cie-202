#pragma once

#include "Action.h"
#include "../ApplicationManager.h"
#include"..\Components\Component.h"
#include <iostream>
#include<fstream>

using namespace std;

class Loadcircuit : public Action {
ifstream myfile;
	//Loadcircuit(void);
public:
	Loadcircuit(ApplicationManager* pApp);
	
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~Loadcircuit(void);
};

