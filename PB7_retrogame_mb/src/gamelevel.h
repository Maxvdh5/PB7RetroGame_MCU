#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include "config.h"
#include <cstdint>

enum PLAYER_DIRECTION {
    PLAYER_DIR_NONE,
    PLAYER_DIR_UP,
    PLAYER_DIR_LEFT,
    PLAYER_DIR_RIGHT,
};

enum LEVEL_STATE {
    LEVEL_DEATH,
    LEVEL_FINISH,
    LEVEL_INPROGRESS,
};

class Block;
class MoveableBlock;
class GpioHandler;

/** Contains the gamestate and every object of a level **/

class GameLevel
{
public:
    GameLevel(uint8_t levelIndex);
    virtual ~GameLevel();

private:
    Block           *m_blocks[MAX_BLOCKS];
    MoveableBlock   *m_playerBlock;

    bool            performMovement();
    bool            checkCollission();

public:
    LEVEL_STATE     m_state; ///< Stores the state the game is in

    bool            update();///<updates a frame
    bool            movePlayerBlock(PLAYER_DIRECTION direction);///< moves player
    bool            writeLocationData(GpioHandler* targetGpio);///<changes location data of every dynamic object
};

#endif // GAMELEVEL_H
