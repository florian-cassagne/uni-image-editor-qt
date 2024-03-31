#ifndef ACTIONS_H
#define ACTIONS_H

#include <QList>
#include "action.h"


class Actions
{
public:
    Actions();

    inline ImageContainer* applyNew() {
        foreach (Action action, listAction) {
            action.applyNew();
        }
        return listAction[0].affectedImage;
    }

    inline ImageContainer* applyOld() {
        foreach (Action action, listAction) {
            action.applyOld();
        }
        return listAction[0].affectedImage;
    }

    inline void addAction(Action* action){
        listAction.append(*action);
    }

private:
    QList<Action> listAction;
};

#endif // ACTIONS_H
