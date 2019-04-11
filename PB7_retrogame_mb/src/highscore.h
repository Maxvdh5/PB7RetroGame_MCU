#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "states.h"

class Highscore : public States
{
public:
    Highscore();


    void update() override;
    void insertObjects(int) override;
    void doGravity() override;
    void checkCollision() override;

    void jump(Object *) override;

    objectList *getObjects() override;

    void createObjects() override;
    void goDown() override;
    void switchSelected(Object*) override;
    int doSelected() override;
    void setSelected() override;
    void goLeft() override;
    void goRight() override;
    void goStop() override;
};

#endif // HIGHSCORE_H
