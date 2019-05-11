#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>

enum BLOCKTYPE {
    BLOCK_DISABLED        = -1,///<test2
    BLOCK_STATIC_ENV      = 0,
    BLOCK_DYNAMIC_PLAYER  = 1,
    BLOCK_DYNAMIC_PUSH    = 2,
    BLOCK_STATIC_FINISH   = 3,
    BLOCK_STATIC_SPRITE   = 4,
    BLOCK_STATIC_FLOOR	  = 5,
};

struct BLOCKDATA {
    int16_t     x; ///< Horizontal position
    int16_t     y; ///< Vertical Position
    //TODO: adapt leveldata generation script to use BLOCKTYPE identifiers and change this to BLOCKTYPE
    int8_t      type; ///< Defines the blockType
};

class Block
{
public:
    Block(struct BLOCKDATA data); ///< Creates a new block

public:
    int16_t    x; ///< Horizontal position
    int16_t    y; ///< Vertical Position
    BLOCKTYPE  type; ///< Defines the blockType

};

#endif // BLOCK_H
