 #ifndef OBJECT_H
#define OBJECT_H

class objectList;

class Object
{
public:
    Object();

//    enum Direction
//                       {NO_MOVEMENT = 0b0000,
//                        N           = 0b1000,
//                        NE          = 0b1100,
//                        E           = 0b0100,
//                        SE          = 0b0110,
//                        S           = 0b0010,
//                        SW          = 0b0011,
//                        W           = 0b0001,
//                        NW          = 0b1001
//                   };

    Object(int,int,int,int,int,bool,bool,bool,Object*);

    Object *getNext();

//   Direction operator|(const Direction &b) const;

    int getX();
    int getVelX();
    int getY();
    int getVelY();
    int getSprite();
    bool getDeathly();
    bool getIsStatic();
    bool getIsSelected();

    void setX(int);
    void setVelX(int);
    void setY(int);
    void setVelY(int);
    void setSprite(int);
    void setDeathly(bool);
    void setIsStatic(bool);
    void setIsSelected(bool);

    void doUpdate();
    void doGravity();


    void moveUp();
    void moveLeft();
    void moveRight();
    void moveStop();

//    Direction direction;

public:


private:
    int x;
    int velX;
    int y;
    int velY;
    int sprite;
    bool deathly;
    bool isSelected;
    bool isStatic;


    Object * volgende;

};



#endif // OBJECT_H
