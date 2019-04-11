#ifndef GAME_H
#define GAME_H

#include "states.h"

/*! \mainpage Game logic documentation
 *
 * \section intro_sec Introduction
 *
 * This document contains the documentation for the game logic for project RetroGame
 *
 */

class Level;
class objectList;


/**
 * @brief The Game class
 * is the main class this class controlls the whole game
 */

class Game
{
public:
     /** Default constructor. initializes the variables used to controll the game
      */
    Game();
    /** Default destructor.
     */
    ~Game();

    /** not used in the final built
     */
   bool getExit();
    /** not used in the final built
     **/
   void doSomething();
    /**
     * @brief runFrame
     * runs the logic for one frame
     */
   void runFrame();
   /**
    * @brief writeFrame
    * is used to send the data to the FPGA
    */
   void writeFrame(GpioHandler *targetGpio);
   /**
    * @brief startState
    * runs interfacing with start state
    * @return returns the next state
    */
   int startState();
   /**
    * @brief levelState
    * runs interfacing with level state
    * @return returns the next state
    */
   int levelState();
   /**
    * @brief highscoreState
    * runs interfacing with highscore state
    * @return returns next state
    */
   int highscoreState();
   /**
    * @brief inputHandeler
    * checks which buttons are pressed
    */
   void inputHandeler(unsigned char);
   /**
    * @brief IsBitSet
    * checks if bit is set
    * @return returns if bit is set
    */
   bool IsBitSet( unsigned char, int);

private:
    bool exit;
    States * states;
    int locIndex;
    int index;
    int levelSelector;
    int death;
    objectList * objects;

};

#endif // GAME_H
