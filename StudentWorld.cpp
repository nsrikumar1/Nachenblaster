#include "StudentWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetDir)
: GameWorld(assetDir)
{
}
StudentWorld::~StudentWorld()
{
    for (int i=0;i<str.size();i++)
    {
        delete str[i];
    }
    delete b;
}

int StudentWorld::init()
{
    b=new NachenBlaster(this);
    for (int i=0;i<30;i++)
    {
        int x=randInt(0,VIEW_WIDTH-1);
        int y=randInt(0,VIEW_HEIGHT-1);
        double res=(randInt(5,50))/100.0;
        
        str.push_back(new Star(x,y,res)); //ask about duplicates
        
    }
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    b->doSomething();
    int rand=randInt(1,15);
    if (rand==1)
    {
        double res=(randInt(5,50))/100.0;
        int y=randInt(0,VIEW_HEIGHT-1);
        str.push_back(new Star(VIEW_WIDTH-1,y,res));
        
    }
    for (int i=0;i<str.size();i++)
    {
        str[i]->doSomething();
        if (str[i]->type()=="Star" && !str[i]->getAlive())
        {
            delete str[i];
            for (int j=i;j<str.size();j++)
            {
                str[j]=str[j+1];
            }
            str.pop_back();
            
        }
        
        
    }
    
    
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    for (int i=0;i<str.size();i++)
    {
        delete str[i];
    }
    delete b;
}
