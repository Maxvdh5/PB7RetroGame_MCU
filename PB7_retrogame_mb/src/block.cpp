#include "block.h"

Block::Block(struct BLOCKDATA data)
{
    this->x     = data.x;
    this->y     = data.y;
    this->type  = static_cast<BLOCKTYPE>(data.type);
}
