#ifndef LEVEL_H
#define LEVEL_H

class objectList;
class Object;
#include "states.h"


/**
 * @brief The Level class
 * is used to controll all the gamelogic
 */
class Level : public States
{
public:
    Level();
    /**
     * @brief Level
     * default constructor. selects the current level
     */

    Level(int);
    ~Level();

    /**
     * @brief update
     * updates the objects
     */
    void update();

    /**
     * @brief insertObjects
     * creates the objects at the start of a level
     */
    void insertObjects(int);

    /**
     * @brief doGravity
     * checks if object is not static and runs gravity on it
     */
    void doGravity();

    /**
     * @brief checkCollision
     * checks for evey dynamic object if ther is a collition
     */
    void checkCollision();

    /**
     * @brief goLeft
     * moves player left
     */
    void goLeft();

    /**
     * @brief goRight
     * moves player right
     */
    void goRight();

    /**
     * @brief goStop
     * stops the player from moving
     */
    void goStop();

    /**
     * @brief jump
     * checks if an object can jump and if possibe makes the object jump
     */
    void jump(Object *);

    objectList *getObjects();



    void createObjects() override;
    void goDown() override;
    void switchSelected(Object*) override;
    int doSelected() override;
    void setSelected() override;


private:
    objectList * list;
    int nextState;
};

#endif // LEVEL_H
