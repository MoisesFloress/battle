#include <player.h>
#include <timer.h>
#include <textureLoader.h>


timer *T = new timer();
textureLoader runTextleft[14];
textureLoader runText[9];
textureLoader stand[0];
textureLoader jump[9];

player::player()
{
    //ctor
    verticies[0].x = 0.0;verticies[0].y = 0.0;verticies[0].z = -1.0;
    verticies[1].x = 1;verticies[1].y = 0.0;verticies[1].z = -1.0;
    verticies[2].x = 1;verticies[2].y = 1.0;verticies[2].z = -1.0;
    verticies[3].x = 0.0;verticies[3].y = 1.0;verticies[3].z = -1.0;

    runspeed  =0;
    jumpspeed =0;
    actionTrigger =0;
}

player::~player()
{
    //dtor
}
void player::drawPlayer()
{
  //  glColor3f(1.0,0.0,0.0);
   // glPushMatrix();
  glBegin(GL_QUADS);

    glTexCoord2f(0.0,1.0);
    glVertex3f(verticies[0].x,verticies[0].y,verticies[0].z);

    glTexCoord2f(1,1.0);
    glVertex3f(verticies[1].x,verticies[1].y,verticies[1].z);

    glTexCoord2f(1,0.0);
    glVertex3f(verticies[2].x,verticies[2].y,verticies[2].z);

    glTexCoord2f(0.0,0.0);
    glVertex3f(verticies[3].x,verticies[3].y,verticies[3].z);

    glEnd();

 //   glPopMatrix();
}

void player::playerInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    T->start();

    stand[0].bindTexture("images/player/Attack__009.png");







    jump[0].bindTexture("images/player/Attack__000.png");
    jump[1].bindTexture("images/player/Attack__001.png");
    jump[2].bindTexture("images/player/Attack__002.png");
    jump[3].bindTexture("images/player/Attack__003.png");
    jump[4].bindTexture("images/player/Attack__004.png");
    jump[5].bindTexture("images/player/Attack__005.png");
    jump[6].bindTexture("images/player/Attack__006.png");
    jump[7].bindTexture("images/player/Attack__007.png");
    jump[8].bindTexture("images/player/Attack__008.png");
    jump[9].bindTexture("images/player/Attack__009.png");




    runText[0].bindTexture("images/player/Jump_Attack__000.png");
    runText[1].bindTexture("images/player/Jump_Attack__001.png");
    runText[2].bindTexture("images/player/Jump_Attack__002.png");
    runText[3].bindTexture("images/player/Jump_Attack__003.png");
    runText[4].bindTexture("images/player/Jump_Attack__004.png");
    runText[5].bindTexture("images/player/Jump_Attack__005.png");
    runText[6].bindTexture("images/player/Jump_Attack__006.png");
    runText[7].bindTexture("images/player/Jump_Attack__007.png");
    runText[8].bindTexture("images/player/Jump_Attack__008.png");
    runText[9].bindTexture("images/player/Jump_Attack__009.png");




    runTextleft[0].bindTexture("images/player/Run (1)l.png");
    runTextleft[1].bindTexture("images/player/Run (2)l.png");
    runTextleft[2].bindTexture("images/player/Run (3)l.png");
    runTextleft[3].bindTexture("images/player/Run (4)l.png");
    runTextleft[4].bindTexture("images/player/Run (5)l.png");
    runTextleft[5].bindTexture("images/player/Run (6)l.png");
    runTextleft[6].bindTexture("images/player/Run (7)l.png");
    runTextleft[7].bindTexture("images/player/Run (8)l.png");
    runTextleft[8].bindTexture("images/player/Run (9)l.png");
    runTextleft[9].bindTexture("images/player/Run (10)l.png");
    runTextleft[10].bindTexture("images/player/Run (11)l.png");
    runTextleft[11].bindTexture("images/player/Run (12)l.png");
    runTextleft[12].bindTexture("images/player/Run (13)l.png");
    runTextleft[13].bindTexture("images/player/Run (14)l.png");
    runTextleft[14].bindTexture("images/player/Run (15)l.png");


}

void player::actions(int action)
{
   switch(action){
   case 0:
       glPushMatrix();
       glTranslated(-0.8,-1.3,-1.0);

       if(T->getTicks()>1){
        idlespeed++;
        idlespeed = idlespeed %1;
        T->reset();
       }

       stand[idlespeed].binder();
      //  glutSolidTeapot(1.5);
       drawPlayer();
       glPopMatrix();
       break;

   case 1:
       glPushMatrix();
       glTranslated(-0.8,-1.3,-1.0);

       if(T->getTicks()>100){

        runspeed++;
        runspeed = runspeed %10;
        T->reset();
       }

       runText[runspeed].binder();
       drawPlayer();
       glPopMatrix();
       break;

   case 2:
    glPushMatrix();


    //jumpspeed = 1;
    glTranslated(-0.8,-1.3, -1.0);

   // for(int i = 0; i < -1.2; i++)
    if(T->getTicks()>50){
        jumpspeed++;
        jumpspeed = jumpspeed%10;
        T->reset();
    }
    jump[jumpspeed].binder();

    drawPlayer();
    glPopMatrix();

    break;

   case 3:
/*
    glPushMatrix();
       glTranslated(-0.8,-1.3,-1.0);

       if(T->getTicks()>25){

        runspeed++;
        runspeed = runspeed %10;
        T->reset();
       }

       runTextleft[runspeed].binder();
       drawPlayer();

       glPopMatrix();
*/
        break;
   }
}




