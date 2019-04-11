#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include "object.h"
#include "GpioHandler.h"


/**
 * @brief The objectList class
 * is used to store objects
 */
class objectList
{
public:
    objectList();
    ~objectList();

    /**
     * @brief insertObject
     * inserts an Object in the list
     */
    void insertObject(int,int,int,int,int,bool,bool,bool);

    /**
     * @brief printObjects
     * Debug function to check the objects
     */
    void printObjects(GpioHandler *targetGpio);
    /**
     * @brief getFirst
     * @return returns the first object in the list
     */
    Object * getFirst();

private:
    int length;
    Object * first;
};

#endif // OBJECTLIST_H
