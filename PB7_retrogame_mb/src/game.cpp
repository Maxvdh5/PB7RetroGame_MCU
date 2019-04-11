#include "game.h"
#include "objectlist.h"
#include "object.h"
#include "level.h"
#include "start.h"
#include "highscore.h"
#include "states.h"
#include "GpioHandler.h"


Game::Game()
{
    this->exit = false;
    states = new start();
    this->objects = nullptr;
    this->index = 0;
    this->locIndex = 0;
    this->levelSelector = 0;
    this->death = 0;
}

Game::~Game()
{

}

bool Game::getExit()
{
    return this->exit;
}

void Game::runFrame()
{
    index = locIndex;

    switch(index)
    {
    case 0:
        delete states;
        states = new start();
        locIndex = startState();
        break;

    case 1:
        delete states;
        states = new Level(levelSelector) ;
        locIndex = levelState();
        break;

    case 10:
        //win scherm
        locIndex = 0;
        break;

    case 11:
        //gameover scherm
    	death = 0;
        locIndex = 0;
        break;

    case 50: //level won
        if(levelSelector < 2)//aantal levels
        {
            levelSelector++;
            locIndex = 1;
        }
        else
        {
            locIndex = 10;
        }
        break;
     case 51:   //gameover
        death++;

        if(death <= 3)
        {
            locIndex = 1;
        }
        else
        {
            locIndex = 11;
        }
        break;

    case 98: locIndex = levelState(); break;
    case 99: locIndex = startState(); break;
    }


}

void Game::writeFrame(GpioHandler *targetGpio)
{
    this->objects = this->states->getObjects();
    this->objects->printObjects(targetGpio);
       //this->exit = true;
}

int Game::startState()
{
    //do interupt stuff
    return this->states->doSelected();
}

int Game::levelState()
{
    //do interupt stuff
    this->states->doGravity();
    this->states->checkCollision();
    this->states->update();
    return this->states->doSelected();
}

int Game::highscoreState()
{
    return 0;
}

void Game::inputHandeler(unsigned char input)
{
    if(IsBitSet(input,3))
    {
        this->states->goDown();
    }
    if(IsBitSet(input,2))
    {
        this->states->goRight();
    }
    if(IsBitSet(input,1))
    {
        this->states->goLeft();
    }
    if(IsBitSet(input,0))
    {
        this->states->jump(this->states->getObjects()->getFirst());
    }
    if(input == 0)
    {
    	this->states->goStop();
    }
}

bool Game::IsBitSet(unsigned char byte, int index)
{
    int mask = 1<<index;
    return (byte & mask) != 0;
}


