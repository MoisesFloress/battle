#include "Battle.h"
#include <objects.h>

Battle::Battle()
{
    //ctor
    herohp = 100;
    monsterhp = 100;
    heropowerweak = 10;
    heropowerstrong = 20;
    monsterpower = 50;
    fight = 1;
}

Battle::~Battle()
{
    //dtor
}
void Battle::playerattackweak()
{
        monsterhp =- heropowerweak;
}
void Battle::playerattackstrong()
{
    monsterhp=- heropowerstrong;
}

void Battle::playerdeath(objects* obj)
{

        for (int i = 0; i < 4; i++)
          {
              obj[i].isObjectLive = false;
          }
}
void Battle::monsterattack()
{

        herohp =- monsterpower;
}



void Battle::monsterdeath()
{

}
