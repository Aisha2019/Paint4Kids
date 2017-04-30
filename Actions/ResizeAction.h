#ifndef __ResizeAction_h__
#define __ResizeAction_h__

#include "Action.h"
#include "../ApplicationManager.h"

#include "../Figures/CCircle.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTrngl.h"
#include "../Figures/CLine.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

#include <cmath>

//Add Resize Action class
class ResizeAction : public Action
{
public:
	ResizeAction(ApplicationManager* app_p);

	void SetResizeFactor(double r_factor);
	void SetCenter(Point r_center);

	virtual void ReadActionParameters();
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

private:
	double resize_factor;
	Point center;
};

#endif  /* __ResizeAction_h__ */