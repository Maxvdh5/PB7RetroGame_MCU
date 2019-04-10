//#include <iostream>

#include "objectlist.h"
#include "object.h"

objectList::objectList()
{
    this->length = 0;
    this->first = nullptr;
}

objectList::~objectList()
{
    while(this->first != nullptr)
    {
        Object * del = this->first;
        this->first = this->first->getNext();
        delete del;
    }
}

void objectList::insertObject(int x, int y,int velX,int velY, int sprite ,bool deathly, bool isStatic,bool isSelected)
{
    Object * newObject = new Object(x, y, velX, velY, sprite, deathly, isStatic,isSelected, this->first);
    this->first = newObject;
    length++;
}

void objectList::printObjects(GpioHandler *targetGpio)
{
    Object * index = this->first;

    while(index != nullptr)
    {
    	targetGpio->write(0x11010000 + index->getX());
    	targetGpio->write(0x11020000 + index->getY());
    	targetGpio->write(0x11030000 + index->getSprite());
    	targetGpio->write(0x11040000);
    	index = index->getNext();
    }
}

Object *objectList::getFirst()
{
    return this->first;
}
