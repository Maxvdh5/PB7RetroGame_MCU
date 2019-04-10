#ifndef GAME_H
#define GAME_H

#include "states.h"

class Level;
class objectList;

class Game
{
public:
    Game();
    ~Game();

   bool getExit();

   void doSomething();

   void runFrame();
   void writeFrame(GpioHandler *targetGpio);

   int startState();
   int levelState();
   int highscoreState();

private:
    bool exit;
    //Level * level;
    States * states;
    int locIndex;
    int index;
    objectList * objects;

};

#endif // GAME_H
