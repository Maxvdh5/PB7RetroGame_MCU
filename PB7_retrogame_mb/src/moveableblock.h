#ifndef MOVEABLEBLOCK_H
#define MOVEABLEBLOCK_H

#include "block.h"

class MoveableBlock : public Block
{
public:
    MoveableBlock(struct BLOCKDATA data);

public:
    int8_t      velX;
    int8_t      velY;

    void        updatePosition();
};

#endif // MOVEABLEBLOCK_H
