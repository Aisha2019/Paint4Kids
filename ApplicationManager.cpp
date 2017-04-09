#include "ApplicationManager.h"

// actions files
#include "Actions/AddRectAction.h"
#include "Actions/AddLineAction.h"
#include "Actions/ExitAction.h"
#include "Actions/SwitchDrawMode.h"
#include "Actions/SwitchPlayMode.h"

//Constructor
ApplicationManager::ApplicationManager()
{
    //Create Input and output
    out_p = new Output;
    in_p = out_p->CreateInput();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
    //Ask the input to get the action from the user.
    return in_p->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
    Action* act_p = NULL;

    //According to Action Type, create the corresponding action object
    switch (ActType) {
		case DRAW_RECT:
			act_p = new AddRectAction(this);
			break;

		case DRAW_LINE:
			///create AddLineAction here
            act_p = new AddLineAction(this);
			break;

		case EXIT:
			///create ExitAction here
            act_p = new ExitAction(this);
			break;

        case TO_PLAY:
            act_p = new SwitchPlayMode(this);
            break;

        case TO_DRAW:
            act_p =  new SwitchDrawMode(this);
            break;

		case STATUS: //a click on the status bar ==> no action
			return;
    }

    //Execute the created action
    if (act_p != NULL) {
        act_p->Execute(); //Execute
        delete act_p; //Action is not needed any more ==> delete it
        act_p = NULL;
    }
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* fig_p)
{
    fig_list.push_back(fig_p);
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
    //If a figure is found return a pointer to it.
    //if this point (x,y) does not belong to any figure return NULL

    ///Add your code here to search for a figure given a point x,y

    return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
    for (int i = 0; i < fig_list.size(); i++)
        fig_list[i]->Draw(out_p); //Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
    return in_p;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
    return out_p;
}
////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::SaveAll(ofstream& out_file)
{
    // TODO
    // iterate through all figures 
    // call save for each one 
}
void ApplicationManager::LoadAll(ifstream& in_file)
{
    // TODO
    // iterate through lines and make the apropriate figure
    // call load for the figure
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
    for (int i = 0; i < fig_list.size(); i++)
        delete fig_list[i];
    delete in_p;
    delete out_p;
}
