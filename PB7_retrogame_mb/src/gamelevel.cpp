#include "gamelevel.h"
#include "leveldata.h"
#include "moveableblock.h"
#include "GpioHandler.h"

GameLevel::GameLevel(uint8_t levelIndex)
{
    uint8_t i;
    for (i = 0; i < MAX_DYNAMIC_BLOCKS; i++) {
        this->m_blocks[i]   = new MoveableBlock(blockLocations[levelIndex][i]);
    }
    for (; i < MAX_BLOCKS; i++) {
        this->m_blocks[i]   = new Block(blockLocations[levelIndex][i]);
    }

    m_playerBlock	= reinterpret_cast<MoveableBlock*>(m_blocks[0]);
    m_state = LEVEL_INPROGRESS;
}

GameLevel::~GameLevel()
{
    for (int i = 0; i < MAX_BLOCKS; i++) {
        delete this->m_blocks[i];
    }
}

bool GameLevel::performMovement()
{
	MoveableBlock	*dynBlock;
	for (int di = 0; di < MAX_DYNAMIC_BLOCKS; ++di) {
		dynBlock	= reinterpret_cast<MoveableBlock*>(m_blocks[di]);
		dynBlock->updatePosition();
	}
	return true;
}

bool GameLevel::checkCollission()
{
	auto determineAlignment = [] (Block *dyn, Block *col, int16_t Block::*axis)
	{
		return (((dyn->*axis) >= (col->*axis) && (dyn->*axis) < (col->*axis)+BLOCK_SIZE)
				||
				((dyn->*axis)+BLOCK_SIZE > (col->*axis) && (dyn->*axis)+BLOCK_SIZE <= (col->*axis)+BLOCK_SIZE));
	};

	auto calculateNewVelocity = [] (MoveableBlock *dyn, Block *col, bool colIsDynamic = false,
			int8_t MoveableBlock::*velAxis)
	{
		if (0 == (dyn->*velAxis))
			return int8_t(0);

		int8_t	direction 		= ((dyn->*velAxis) < 0) ? -1 : 1;
		int16_t Block::*axis	= (&MoveableBlock::velX == velAxis) ? &Block::x : &Block::y;
		int16_t gap				= ((dyn->*axis)+(dyn->*velAxis))-(col->*axis);
		gap						= (0 > gap) ? -gap : gap; // get absolute gap
		gap						= gap - BLOCK_SIZE;

		if (0 > gap && !colIsDynamic)
			return static_cast<int8_t>((dyn->*velAxis)+(direction*gap));
		// set moveable block velocity
		else if (0 > gap && colIsDynamic)
			(reinterpret_cast<MoveableBlock*>(col)->*velAxis) = (dyn->*velAxis);

		return (dyn->*velAxis);
	};


	for (uint8_t di = 0; di < MAX_DYNAMIC_BLOCKS; di++) {
		if (BLOCK_DISABLED == m_blocks[di]->type)
			continue;
		MoveableBlock 	*dynBlock 		= reinterpret_cast<MoveableBlock*>(m_blocks[di]);
		for (uint8_t bi = 0; bi < MAX_BLOCKS; bi++) {
			// skip unused blocks and self
			if (BLOCK_DISABLED == m_blocks[bi]->type
				|| di == bi)
				continue;
			bool xAligned	= determineAlignment(dynBlock, m_blocks[bi], &Block::x);
			bool yAligned	= determineAlignment(dynBlock, m_blocks[bi], &Block::y);
			// horizontal
			if (yAligned)
				dynBlock->velX	= calculateNewVelocity(dynBlock, m_blocks[bi],
						(bi < MAX_DYNAMIC_BLOCKS), &MoveableBlock::velX);
			// vertical
			if (xAligned)
				dynBlock->velY	= calculateNewVelocity(dynBlock, m_blocks[bi],
						false, &MoveableBlock::velY);
		}
	}
	return true;
}

bool GameLevel::update()
{
	checkCollission();
	performMovement();
	return true;
}

bool GameLevel::movePlayerBlock(PLAYER_DIRECTION direction)
{
    switch (direction) {
    case PLAYER_DIR_UP:
//        if (0 > m_playerBlock->velY)
            m_playerBlock->velY = -PLAYER_JUMP_HEIGHT;
        break;
    case PLAYER_DIR_LEFT:
        m_playerBlock->velX     = -PLAYER_MOVE_SPEED;
        break;
    case PLAYER_DIR_RIGHT:
        m_playerBlock->velX     = PLAYER_MOVE_SPEED;
        break;
    default:
        m_playerBlock->velX     = 0;
    	break;
    }

    return true;
}

bool GameLevel::writeLocationData(GpioHandler *targetGpio)
{
    for (uint8_t i = 0; i < MAX_BLOCKS; i++) {
       if (BLOCK_DISABLED == m_blocks[i]->type)
           continue;
       targetGpio->write(0x11010000 + m_blocks[i]->x);
       targetGpio->write(0x11020000 + m_blocks[i]->y);
       targetGpio->write(0x11030000 + m_blocks[i]->type);
       targetGpio->write(0x11040000);
    }
    return true;
}
