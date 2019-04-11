#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include "object.h"
#include "GpioHandler.h"

class objectList
{
public:
    objectList();
    ~objectList();
    void insertObject(int,int,int,int,int,bool,bool,bool);

    void printObjects(GpioHandler *targetGpio);
    Object * getFirst();

private:
    int length;
    Object * first;
};

#endif // OBJECTLIST_H
