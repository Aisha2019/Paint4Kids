#include "PickAction.h"

PickAction::PickAction(ApplicationManager * app_p) :Action(app_p)
{
}

void PickAction::ReadActionParameters()
{
	Input *in_p = manager_p->GetInput();
	Output *out_p = manager_p->GetOutput();
	out_p->CreatePickBar();
	act = in_p->GetUserAction();
	out_p->ClearTToolBar();
}

void PickAction::Execute()
{
	manager_p->ExecuteAction(act);
}

void PickAction::Undo()
{
}