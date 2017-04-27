#ifndef _DELETEAction_
#define _DELETEAction_

#include "../ApplicationManager.h"
#include "Action.h"

class DeleteAction : public Action {
public:
    DeleteAction(ApplicationManager* app_p);

    virtual void ReadActionParameters();
    virtual void Execute();

    virtual void Undo();

private:
    deque<CFigure*> clipboard;
    bool deleted = false;
};

#endif