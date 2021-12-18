#pragma once

#include ".\Actions\action.h"
#include ".\Components\Resistor.h"

class ActionAddBuzz : public Action
{
private:
	
	int Cx, Cy;	
	int x1, y1, x2, y2;	
public:
	ActionAddBuzz(ApplicationManager* pApp);
	virtual ~ActionAddBuzz(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};

