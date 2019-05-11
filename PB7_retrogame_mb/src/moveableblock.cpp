#include "moveableblock.h"
#include "config.h"

MoveableBlock::MoveableBlock(struct BLOCKDATA data) : Block(data)
{
	velX	= 0;
	velY	= 0;
}

void MoveableBlock::updatePosition()
{
	x			+=	velX;
	y			+=	velY;

	isAirborne	= 	(0 != velY);

	if (MAX_VELOCITY > velY)
		velY++;

	if (0 > velX)
		velX++;
	else if (0 < velX)
		velX--;
}
