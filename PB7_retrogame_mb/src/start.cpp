#include "start.h"

start::start()
{
    list = new objectList;
    createObjects();

    this->selected = this->list->getFirst();
}

start::~start()
{
    delete this->list;
}

void start::createObjects()
{
    list->insertObject(30,70,0,0,1,false,true,false);
    list->insertObject(30,50,0,0,1,false,true,false);
    list->insertObject(30,30,0,0,1,false,true,true);
}

void start::goDown()
{
    Object * looper = this->list->getFirst();
    while (looper->getNext()!= nullptr)
    {
        looper = looper->getNext();
    }

    if(this->selected != looper)
    {
        switchSelected(selected->getNext());
    }
}


void start::switchSelected(Object * switcher)
{
    this->selected->setIsSelected(false);
    switcher->setIsSelected(true);
    this->selected = switcher;
}

int start::doSelected()
{
    if(select)
    {
        Object * looper = this->list->getFirst();
        select = false;
        for(int i =1; i < 10; i++){     // 1 = first element in start 2 = second etc
            if(selected == looper)
            {
                return i;
            }
        }
    }
    return 99;
}

void start::setSelected()
{
   // this->select = true;
}

void start::goLeft()
{

}

void start::goRight()
{
    this->select = true;
}

void start::update()
{

}

void start::insertObjects()
{

}

void start::doGravity()
{
// intentinaly left empty
}

bool start::checkCollision()
{
    return false;
}

void start::goStop()
{

}

void start::jump(Object *)
{

    if(this->selected != this->list->getFirst())
    {
        Object * looper = this->list->getFirst();

        while(looper->getNext() != this->selected)
        {
            looper = looper->getNext();
        }

        switchSelected(looper);
    }

}

objectList* start::getObjects()
{
    return this->list;
}
