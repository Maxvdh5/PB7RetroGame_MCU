#ifndef START_H
#define START_H

#include "object.h"
#include "objectlist.h"
#include "states.h"

/**
 * @brief The start class
 * is used for the startscreen
 */

class start : public States
{
public:
    start();
    ~start();

    /**
     * @brief createObjects
     * creates start screen objects
     */
    void createObjects();

    /**
     * @brief goDown
     * moves down
     */
    void goDown();

    /**
     * @brief switchSelected
     * switches the selected option
     */
    void switchSelected(Object*);
    /**
     * @brief doSelected
     * @return returns the new selected state
     */
    int doSelected();

    /**
     * @brief setSelected
     * is used to sed the select variable
     */
    void setSelected();


    void goLeft() override;
    void goRight() override;
    void update() override;
    void insertObjects(int) override;
    void doGravity() override;
    void checkCollision() override;
    void goStop() override;

    void jump(Object *) override;

    objectList *getObjects() override;

private:
        objectList * list;
        Object * selected;
        bool select;
};

#endif // START_H
