#include "game.h"
#include "gamelevel.h"
#include "leveldata.h"

Game::Game()
{
    currentLevelIndex   = 0;
    playerLives         = PLAYER_LIVES;
    gameLevel           = nullptr;

    switchLevel();
}

void Game::runFrame(GpioHandler *targetGpio)
{
    switch (currentState) {
    case SWITCHING_LEVEL:
        return;
    case GAME_LEVEL:
        gameLevel->update();
        processLevelState();
        break;
    case MAIN_MENU:
        break;
    }
    gameLevel->writeLocationData(targetGpio);
}

void Game::switchLevel()
{
    currentState        = SWITCHING_LEVEL;

    if (nullptr != gameLevel)
        delete gameLevel;

    gameLevel           = new GameLevel(currentLevelIndex);

    if (currentLevelIndex == 0)
    {
        currentState    = MAIN_MENU;
        return;
    }

    currentState        = GAME_LEVEL;
}

void Game::processLevelState()
{
	switch (gameLevel->m_state) {
		case LEVEL_INPROGRESS:
			return;
		case LEVEL_DEATH:
			if (0 >= --playerLives)
			{
				//TODO: GAME OVER level
				playerLives			= PLAYER_LIVES;
				currentLevelIndex	= 0; // back to main menu
			}
			break;
		case LEVEL_FINISH:
			if (LEVEL_COUNT <= ++currentLevelIndex)
				//TODO: highscore/victory level
				currentLevelIndex	= 0; // back to main menu
			break;
		default:
			break;
	}
	switchLevel();
}

void Game::handleUserInput(uint8_t inputData)
{
	/*
	 * inputData:
	 * [7:4][  3  ][  2  ][  1 ][0 ]
	 *   -   Reset  Right  Left  Up
	 */

    // drop user input if SWITCHING_LEVEL
    if (SWITCHING_LEVEL == currentState)
        return;

    static uint8_t		oldInputData	= 0x0;
    uint8_t				dirUp			= (inputData^oldInputData)&0x1;
    uint8_t				dirLeftRight	= (inputData >> 1) & 0x3;
    uint8_t				reset			= (inputData >> 3) & 0x1;
    PLAYER_DIRECTION    direction   	= PLAYER_DIR_NONE;

    oldInputData						= inputData;

    if (reset)
    {
        switchLevel();
        return;
    }

    if (dirUp)
    	gameLevel->movePlayerBlock(PLAYER_DIR_UP);

    switch (dirLeftRight) {
    case 0x1:
        direction   = PLAYER_DIR_LEFT;
        break;
    case 0x2:
        direction   = PLAYER_DIR_RIGHT;

        if (MAIN_MENU == currentState)
        {
            currentLevelIndex++;
            switchLevel();
            return;
        }
        break;
    case 0x3:
    	direction	= PLAYER_DIR_NONE;
    	break;
    }

    gameLevel->movePlayerBlock(direction);
}
