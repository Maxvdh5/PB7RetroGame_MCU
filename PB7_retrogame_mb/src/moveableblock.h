#ifndef MOVEABLEBLOCK_H
#define MOVEABLEBLOCK_H

#include "block.h"

/** A special type of Block that is dynamic **/

class MoveableBlock : public Block
{
public:
    MoveableBlock(struct BLOCKDATA data); ///< calls the constructor of Block and adds velocity

public:
    int8_t      velX; ///< The horizontal velocity for the next update
    int8_t      velY; ///< The vertical velocity for the next update
    bool        isAirborne; ///< Whether the Block is moving on the y-axis

    void        updatePosition(); ///< Update the Block's velocity
};

#endif // MOVEABLEBLOCK_H
