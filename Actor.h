#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
class StudentWorld;
class Actor: public GraphObject
{
    bool alive=true;
public:
    Actor(int imageID, double startX, double startY, int dir , double size , int depth );
    virtual void doSomething()=0;
    virtual std::string type() =0;
    bool getAlive();
    void setDead();
    
  
};
class NachenBlaster: public Actor
{
    StudentWorld *n;
    int key;
public:
    NachenBlaster(StudentWorld * h);
    virtual void doSomething();
    virtual std::string type();
 
};
class Star: public Actor
{
    public:
    Star(int startx,int starty, double size);
    virtual void doSomething();
    virtual std::string type();
   
};


#endif // ACTOR_H_
