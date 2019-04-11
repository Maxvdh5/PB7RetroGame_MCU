#include "level.h"
#include "object.h"
#include "objectlist.h"


#define size 20

Level::Level()
{

}

Level::Level(int levelSelect)
{
    list = new objectList;
    insertObjects(levelSelect);
    nextState = 98;

}

Level::~Level()
{
    delete this->list;
}

void Level::update()
{
  Object * index = this->list->getFirst();

  while(index != nullptr)
  {
      index->doUpdate();

      index = index->getNext();
  }

}

void Level::insertObjects(int levelSelect)
{

    switch(levelSelect)
    {
        case 0:
        for(int i = 0; i<6; i++)
        {
            list->insertObject(i*size,18*size,0,0,0,false,true,false);
        }
        for(int i = 10; i <19; i++)
        {
            list->insertObject(i*size,17*size,0,0,0,false,true,false);
        }
        for(int i = 17; i < 21; i++)
        {
            list->insertObject(i*size,17*size,0,0,0,false,true,false);
        }
        for(int i = 21; i <24; i++)
        {
            list->insertObject(i*size,15*size,0,0,0,false,true,false);
        }
        for(int i = 15; i <18; i++)
        {
            list->insertObject(i*size,14*size,0,0,0,false,true,false);
        }

        for(int i = 22; i <26; i++)
        {
            list->insertObject(i*size,13*size,0,0,0,false,true,false);
        }
        for(int i = 14; i <18; i++)
        {
            list->insertObject(27*size,i*size,0,0,0,false,true,false);
        }
        for(int i = 28; i <31; i++)
        {
            list->insertObject(i*size,18*size,0,0,0,false,true,false);
        }

        list->insertObject(size*30,size*17,0,0,0,false,false,false);

         list->insertObject(size*2,size*2,0,0,0,false,false,false);
        //level 1





        break;
        case 1:

        for(int i = 0; i<6; i++)
        {
            list->insertObject(i*size,18*size,0,0,0,false,true,false);
        }
        for(int i = 9; i <19; i++)
        {
            list->insertObject(i*size,17*size,0,0,0,false,true,false);
        }
        for(int i = 15; i < 19; i++)
        {
            list->insertObject(i*size,17*size,0,0,0,false,true,false);
        }
        for(int i = 21; i <24; i++)
        {
            list->insertObject(i*size,15*size,0,0,0,false,true,false);
        }
        for(int i = 15; i <18; i++)
        {
            list->insertObject(i*size,14*size,0,0,0,false,true,false);
        }

        for(int i = 22; i <26; i++)
        {
            list->insertObject(i*size,12*size,0,0,0,false,true,false);
        }
        for(int i = 14; i <18; i++)
        {
            list->insertObject(27*size,i*size,0,0,0,false,true,false);
        }
        for(int i = 28; i <31; i++)
        {
            list->insertObject(i*size,18*size,0,0,0,false,true,false);
        }

         list->insertObject(size*2,size*20,0,0,0,false,false,false);
        //level 2



        break;


        case 2:
        //level 3


        break;
    }


}

void Level::doGravity()
{
    Object * index = this->list->getFirst();
    while(index != nullptr)
    {
        index->doGravity();
        index = index->getNext();
    }

}

void Level::checkCollision()//+ directon
{
  Object * moving = list->getFirst();

  if(moving->getY()>460||moving->getVelY()<-size)
  {
      nextState = 51;
      return;
  }
  Object * index =list->getFirst();
  while(moving != nullptr)
  {
      while(index != nullptr)
      {
          if(index != moving && !moving->getIsStatic())
          {
              if((moving->getX()+ moving->getVelX()) - index->getX() <= size && (moving->getY() - index->getY() < size && moving->getY() - index->getY() > -size ))
              {

                  if(moving->getVelX()<0 && moving->getX() > index->getX())
                  {
                     moving->setVelX(((moving->getX()-index->getX())-size)*-1);
                     if(moving == list->getFirst())
                     {
                        if(index->getDeathly())
                        {
                            nextState = 51;
                            return;
                        }
                        else if(index->getIsSelected())
                        {
                            nextState = 50;
                            return;
                        }
                     }
                  }

                  //moving->direction =  static_cast<Object::Direction>(moving->direction & ~moving->E);
              }

              if((moving->getY() + moving->getVelY()) - index->getY()  >= -size && (moving->getX() - index->getX() < size && moving->getX() - index->getX() > -size ))
              {

                  if(moving->getVelY() >0 && moving->getY() < index->getY())
                  {
                      moving->setVelY(((moving->getY()-index->getY())+size)*-1);
                      if(moving == list->getFirst())
                      {
                         if(index->getDeathly())
                         {
                             nextState = 51;
                             return;
                         }
                         else if(index->getIsSelected())
                         {
                             nextState = 50;
                             return;
                         }
                      }
                  }

                 //moving->direction = static_cast<Object::Direction>(moving->direction & ~moving->S);
              }

              if((moving->getX() + moving->getVelX()) - index->getX()  >= -size && (moving->getY() - index->getY() < size && moving->getY() - index->getY() > -size ))
              {

                  if(moving->getVelX()>0 && moving->getX() < index->getX())
                  {
                    moving->setVelX(((moving->getX()-index->getX())+size)*-1);
                    if(moving == list->getFirst())
                    {
                       if(index->getDeathly())
                       {
                           nextState = 51;
                           return;
                       }
                       else if(index->getIsSelected())
                       {
                           nextState = 50;
                           return;
                       }
                    }
                  }

                  //moving->direction = static_cast<Object::Direction>(moving->direction & ~moving->W);
              }

              if((moving->getY() + moving->getVelY() ) - index->getY() <= size && (moving->getX() - index->getX() < size && moving->getX() - index->getX() > -size ))
              {

                  if(moving->getVelY() < 0 && moving->getY() > index->getY())
                  {
                    moving->setVelY(((moving->getY()-index->getY())-size)*-1);
                    if(moving == list->getFirst())
                    {
                       if(index->getDeathly())
                       {
                           nextState = 51;
                       }
                       else if(index->getIsSelected())
                       {
                           nextState = 50;
                       }
                    }
                  }

                  //moving->direction = static_cast<Object::Direction>(moving->direction & ~moving->N);
              }
          }
          index = index->getNext();
      }
      index = list->getFirst();
      moving = moving->getNext();
  }


}

void Level::goLeft()
{
    Object * player = this->list->getFirst();
    player->moveLeft();
}

void Level::goRight()
{
    Object * player = this->list->getFirst();
    player->moveRight();
}

void Level::goStop()
{
    Object * player = this->list->getFirst();
    player->moveStop();
}

void Level::jump(Object * moving)
{
    Object * index = this->list->getFirst();

    while(index != nullptr)
    {
        if(index != moving)
        {
            if(moving->getY()  - index->getY()  >= -size && (moving->getX() - index->getX() < size && moving->getX() - index->getX() > -size ))
            {
                moving->moveUp();
                return;
            }
        }

        index = index->getNext();
    }
}





objectList *Level::getObjects()
{
    return this->list;
}

void Level::createObjects()
{

}

void Level::goDown()
{

}



void Level::switchSelected(Object *)
{

}

int Level::doSelected()
{
    return nextState;
}

void Level::setSelected()
{

}

