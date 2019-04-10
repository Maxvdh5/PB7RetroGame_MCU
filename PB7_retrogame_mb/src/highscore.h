#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "states.h"

class Highscore : public States
{
public:
    Highscore();


    void update() override;
    void insertObjects() override;
    void doGravity() override;
    bool checkCollision() override;

    void jump(Object *) override;

    objectList *getObjects() override;

    void createObjects() override;
    void goDown() override;
    void goUp() override;
    void switchSelected(Object*) override;
    int doSelected() override;
    void setSelected() override;
};

#endif // HIGHSCORE_H
