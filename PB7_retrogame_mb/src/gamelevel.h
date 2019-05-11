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
    GameLevel(uint8_t levelIndex, bool cheatMode = false);
    virtual ~GameLevel();

private:
    Block           *m_blocks[MAX_BLOCKS];
    MoveableBlock   *m_playerBlock;

    bool            m_cheatMode;

    bool            performMovement();
    bool            checkCollission();

public:
    LEVEL_STATE     m_state; ///< Stores the state the level is in

    bool            update();///<updates location data for dynamic objects in the level
    bool            movePlayerBlock(PLAYER_DIRECTION direction);///< moves player
    bool            writeLocationData(GpioHandler* targetGpio);///<writes location data to targetGpio
};

#endif // GAMELEVEL_H
