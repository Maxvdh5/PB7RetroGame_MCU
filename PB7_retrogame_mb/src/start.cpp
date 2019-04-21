#include "start.h"

start::start()
{
    list = new objectList;
    createObjects();
    select = false;

    this->selected = this->list->getFirst();
}

start::~start()
{
    delete this->list;
}

void start::createObjects()
{
    int mainBlockX = 230;
    int mainBlockY;

    for(int hor = 0; hor < 9; hor++)
    {
    	mainBlockY = 200;
   	  for(int ver = 0; ver < 4; ver++)
   	  {
   	    list->insertObject(mainBlockX, mainBlockY,0,0,3,false,true,false);
        mainBlockY += 20;
   	  }
   	  mainBlockX += 20;
    }
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

void start::insertObjects(int)
{

}

void start::doGravity()
{
// intentinaly left empty
}

void start::checkCollision()
{
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
