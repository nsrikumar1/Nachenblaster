#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

Actor::Actor(int imageID, double startX, double startY, int dir=0 , double size=1.0 , int depth = 0)
: GraphObject(imageID, startX,  startY, dir ,  size , depth ) {}
std::string NachenBlaster::type()
{
    return "NachenBlaster";
}
bool Actor::getAlive()
{
    return alive;
}
void Actor::setDead()
{
    alive=false;
}
NachenBlaster::NachenBlaster(StudentWorld * h)
: Actor(IID_NACHENBLASTER, 0,  128, 0, 1.0,  0)
{n=h;}

 void NachenBlaster::doSomething()
{
    if(n->getKey(key))
    {
        if (key==KEY_PRESS_UP&&getY()+6<VIEW_HEIGHT)
            moveTo(getX(),getY()+6);
        else if (key==KEY_PRESS_DOWN &&getY()-6>=0)
            moveTo(getX(),getY()-6);
        else if (key==KEY_PRESS_LEFT && getX()-6>=0)
            moveTo(getX()-6,getY());
        else if (key==KEY_PRESS_RIGHT && getX()+6<VIEW_WIDTH)
            moveTo(getX()+6,getY());
        
    }
}



Star::Star(int startx,int starty, double size)
: Actor(IID_STAR, startx, starty, 0, size,  3) {}  //move and shoot
void Star::doSomething()
{
    if(getX()-1>=0)//check this out
    {
        moveTo(getX()-1,getY());
    }
    else
    {
        setDead();
        
    }
    
}

std::string Star::type()
{
    return "Star";
}

