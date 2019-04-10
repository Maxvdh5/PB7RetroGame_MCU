#include "object.h"


#define jumpHeight 10
#define maxVelosity 12
#define moveSpeed 1

Object::Object()
{

}

Object::Object(int x, int y, int velX, int velY, int sprite, bool deathly, bool isStatic,bool isSelected, Object * volgende)
{
    this->x = x;
    this->velX = velX;
    this->y = y;
    this->velY = velY;
    this->sprite = sprite;
    this->deathly = deathly;
    this->isStatic = isStatic;
    this->isSelected = isSelected;
    this->volgende = volgende;
}


Object *Object::getNext()
{
    return this->volgende;
}

int Object::getX()
{
    return this->x;
}

int Object::getVelX()
{
    return this->velX;
}

int Object::getY()
{
    return this->y;
}

int Object::getVelY()
{
    return this->velY;
}

int Object::getSprite()
{
    return this->sprite;
}

bool Object::getDeathly()
{
    return this->deathly;
}

bool Object::getIsStatic()
{
    return this->isStatic;
}

bool Object::getIsSelected()
{
    return this->isSelected;
}

void Object::setX(int x)
{
    this->x = x;
}

void Object::setVelX(int velX)
{
    this->velX = velX;
}

void Object::setY(int y)
{
    this->y = y;
}

void Object::setVelY(int velY)
{
    this->velY = velY;
}

void Object::setSprite(int sprite)
{
    this->sprite = sprite;
}

void Object::setDeathly(bool deathly)
{
    this->deathly = deathly;
}

void Object::setIsStatic(bool isStatic)
{
    this->isStatic = isStatic;
}

void Object::setIsSelected(bool isSelected)
{
    this->isSelected = isSelected;
}

void Object::doUpdate()
{


    this->setX(getX()+getVelX());
    this->setY(getY()+getVelY());
}

void Object::doGravity()
{
    if(!this->getIsStatic())
    {
        if(this->getVelY() >= maxVelosity)
        {
            setVelY(maxVelosity);
        }
        else
        {
            this->setVelY(getVelY()+1);
        }
    }

}

void Object::moveUp()
{

    this->setVelY(this->getVelY() - jumpHeight);
}

void Object::moveLeft()
{
    this->setVelX(-moveSpeed);
}

void Object::moveRight()
{
    this->setVelX(moveSpeed);
}

void Object::moveStop()
{
    this->setVelX(0);
}
