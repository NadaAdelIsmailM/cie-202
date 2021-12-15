#pragma once

#include "Action.h"
#include "../ApplicationManager.h"

#include <iostream>
#include<fstream>

using namespace std;

class Loadcircuit : public Action {
public:
	//Loadcircuit(void);
public:
	Loadcircuit(ApplicationManager* pApp);
	
	virtual void Execute();
	virtual void loadcircuit();
	virtual void Undo();
	virtual void Redo();
	virtual ~Loadcircuit(void);
};

