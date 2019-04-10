#ifndef STATES_H
#define STATES_H


#include "object.h"
#include "objectlist.h"

class States
{
public:
    States();


    virtual void createObjects()=0;
    virtual void goDown()=0;
    virtual void goUp()=0;
    virtual void switchSelected(Object*)=0;
    virtual int doSelected()=0;
    virtual void setSelected()=0;



    virtual void update()=0;
    virtual void insertObjects()=0;
    virtual void doGravity()=0;
    virtual bool checkCollision()=0;

    virtual void jump(Object *)=0;

    virtual objectList *getObjects()=0;

private:
    objectList * list;
};

#endif // STATES_H
