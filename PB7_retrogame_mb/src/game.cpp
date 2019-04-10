#include "game.h"
#include "objectlist.h"
#include "object.h"
#include "level.h"
#include "start.h"
#include "highscore.h"
#include "states.h"


Game::Game()
{
    this->exit = false;
    states = new start();
    this->objects = nullptr;
    this->index = 0;
    this->locIndex = 0;
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
    case 0: locIndex = startState();  delete states; states = new start(); break;
    case 1: locIndex = levelState(); delete states; states = new Level() ; break;
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
    if(IsBitSet(input,4))
    {
        this->states->goDown();
    }
    if(IsBitSet(input,3))
    {
        this->states->goRight();
    }
    if(IsBitSet(input,2))
    {
        this->states->goLeft();
    }
    if(IsBitSet(input,1))
    {
        this->states->jump(this->states->getObjects()->getFirst());
    }
}

bool Game::IsBitSet(unsigned char byte, int index)
{
    int mask = 1<<index;
    return (byte & mask) != 0;
}


