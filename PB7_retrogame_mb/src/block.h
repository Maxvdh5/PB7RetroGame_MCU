#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>

enum BLOCKTYPE {
    BLOCK_DISABLED        = -1,
    BLOCK_STATIC_ENV      = 0,
    BLOCK_DYNAMIC_PLAYER  = 1,
    BLOCK_DYNAMIC_PUSH    = 2,
    BLOCK_STATIC_FINISH   = 3,
    BLOCK_STATIC_SPRITE   = 4,
};

struct BLOCKDATA {
    int16_t     x;
    int16_t     y;
    //TODO: adapt leveldata generation script to use BLOCKTYPE identifiers and change this to BLOCKTYPE
    int8_t      type;
};

class Block
{
public:
    Block(struct BLOCKDATA data);

// TODO: getters?
public:
    int16_t    x;
    int16_t    y;
    BLOCKTYPE  type;

};

#endif // BLOCK_H
