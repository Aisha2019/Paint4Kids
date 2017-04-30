#include "UnSelectAction.h"

UnSelectAction::UnSelectAction(ApplicationManager* app_p)
    : Action(app_p)
{
}

void UnSelectAction::ReadActionParameters()
{
    Input* in_p = manager_p->GetInput();
    Output* out_p = manager_p->GetOutput();
	out_p->PrintMessage("Click on select figure you want to deselect to deselect all click on a blank area");
    in_p->GetPointClicked(p.x, p.y);
	out_p->ClearStatusBar();
}

void UnSelectAction::Execute()
{
	Output* out_p = manager_p->GetOutput();

    figure = manager_p->GetFigure(p.x, p.y);
	if (figure != nullptr && figure->IsSelected()) {
		figure->SetSelected(false);
		manager_p->SetNumSelected(manager_p->GetNumSelected() - 1);
	}
	else 
		manager_p->DeselectAll();
}

void UnSelectAction::Undo()
{
    if (figure != nullptr && !figure->IsSelected()) {
        figure->SetSelected(true);
		manager_p->SetNumSelected(manager_p->GetNumSelected() + 1);
    }
}