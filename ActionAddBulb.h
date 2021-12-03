#pragma once
#include ".\Actions\action.h"
#include ".\Components\Resistor.h"

class ActionAddBulb : public Action
{
private:

	int Cx, Cy;
	int x1, y1, x2, y2;
public:
	ActionAddBulb(ApplicationManager* pApp);
	virtual ~ActionAddBulb(void);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};

#pragma once
