#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include "config.h"



enum GAMESTATE {
    MAIN_MENU = 0,
    GAME_LEVEL,
    SWITCHING_LEVEL,
};

class GameLevel;
class GpioHandler;


/** the Game class handels all the game logic
**/
class Game
{
public:
    Game();
    void        runFrame(GpioHandler *targetGpio); ///< runs the game for one frame
    void        handleUserInput(uint8_t inputData); ///< is called when an input interupt is recieved

private:
    GAMESTATE   currentState;
    GameLevel   *gameLevel;
    uint8_t     currentLevelIndex;
    uint8_t     playerLives;

    void        switchLevel(bool cheatMode = false);
    void		processLevelState();
};

#endif // GAME_H
