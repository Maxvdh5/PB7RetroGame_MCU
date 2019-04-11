#ifndef LEVEL_H
#define LEVEL_H

class objectList;
class Object;
#include "states.h"

class Level : public States
{
public:
    Level();
    Level(int);
    ~Level();

    void update();
    void insertObjects(int);
    void doGravity();
    void checkCollision();
    void goLeft();
    void goRight();
    void goStop();
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
