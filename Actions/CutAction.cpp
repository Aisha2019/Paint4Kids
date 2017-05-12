#include "CutAction.h"

CutAction::CutAction(ApplicationManager* app_p)
    : Action(app_p, false)
{
}

void CutAction::ReadActionParameters()
{
	Output* out_p = manager_p->GetOutput();
	out_p->ClearStatusBar();
}

void CutAction::Execute()
{
    if (manager_p->GetNumSelected() > 0) {
        clipboard = manager_p->GetClipboard();
        manager_p->FillClipboardWithSelected();
        cut = manager_p->EraseSelected();
        cuted = true;
    }
}

void CutAction::Undo()
{
}