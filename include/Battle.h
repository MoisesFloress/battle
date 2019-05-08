#ifndef BATTLE_H
#define BATTLE_H
#include <objects.h>

class Battle
{
    public:
        Battle();

        int herohp;
        int monsterhp;
        int heropowerweak;
        int heropowerstrong;
        int monsterpower;
        bool fight;

        void playerattackweak();
        void playerattackstrong();
        void monsterattack();
        void playerdeath(objects*);
        void monsterdeath();

        virtual ~Battle();





    private:

};

#endif // BATTLE_H
