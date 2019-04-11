 #ifndef OBJECT_H
#define OBJECT_H

class objectList;


/**
 * @brief The Object class
 * is used to store all the data of an object.
 */
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
    /**
     * @brief getX
     * @return returns x
     */
    int getX();

    /**
     * @brief getVelX
     * @return returns velX
     */
    int getVelX();

    /**
     * @brief getY
     * @return returns y
     */
    int getY();

    /**
     * @brief getVelY
     * @return returns velY
     */
    int getVelY();

    /**
     * @brief getSprite
     * @return returns sprite
     */
    int getSprite();

    /**
     * @brief getDeathly
     * @return returns deathly
     */
    bool getDeathly();

    /**
     * @brief getIsStatic
     * @return returns isStatic
     */
    bool getIsStatic();

    /**
     * @brief getIsSelected
     * @return returns isSelected
     */
    bool getIsSelected();

    /**
     * @brief setX
     * sets X
     */
    void setX(int);

    /**
     * @brief setVelX
     * sets Velx
     */
    void setVelX(int);

    /**
     * @brief setY
     * sets Y
     */
    void setY(int);

    /**
     * @brief setVelY
     * sets velY
     */
    void setVelY(int);

    /**
     * @brief setSprite
     * sets sprite
     */
    void setSprite(int);

    /**
     * @brief setDeathly
     * sets deathly
     */
    void setDeathly(bool);

    /**
     * @brief setIsStatic
     * sets isStatic
     */
    void setIsStatic(bool);

    /**
     * @brief setIsSelected
     * sets isSelected
     */
    void setIsSelected(bool);

    /**
     * @brief doUpdate
     * updates an object and moves it to it's new location
     */
    void doUpdate();
    /**
     * @brief doGravity
     * runs gravity on an Object
     */
    void doGravity();

    /**
     * @brief moveUp
     * decreases Y
     */
    void moveUp();

    /**
     * @brief moveLeft
     * decreases X
     */
    void moveLeft();

    /**
     * @brief moveRight
     * increases X
     */
    void moveRight();

    /**
     * @brief moveStop
     * sets velX to 0
     */
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
