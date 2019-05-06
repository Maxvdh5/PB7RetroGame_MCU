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

class Game
{
public:
    Game();
    void        runFrame(GpioHandler *targetGpio);
    void        handleUserInput(uint8_t inputData);

private:
    GAMESTATE   currentState;
    GameLevel   *gameLevel;
    uint8_t     currentLevelIndex;
    uint8_t     playerLives;

    void        switchLevel();
    void		processLevelState();
};

#endif // GAME_H
