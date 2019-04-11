#ifndef START_H
#define START_H

#include "object.h"
#include "objectlist.h"
#include "states.h"

class start : public States
{
public:
    start();
    ~start();


    void createObjects();
    void goDown();
    void switchSelected(Object*);
    int doSelected();
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
