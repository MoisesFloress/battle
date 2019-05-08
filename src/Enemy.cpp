#include "Enemy.h"
#include <timer.h>
#include <textureLoader.h>



Enemy::Enemy()
{

    xPosE =0.0;             //placing objects on x
    yPosE =0.0;             //placing objects on y
    zPosE = -5.0;             //placing objects on z

    xSizeE = -5.0;            // for scaling x
    ySizeE = -5.0;            // for scaling y

    rotateXE =0.0;
    rotateYE =0.0;
    rotateZE =0.0;
}

Enemy::~Enemy()
{
    //dtor
}



void Enemy::drawEnemy()
{
    if(isEnemyLive)          // check status
    {
      glColor3f(1.0,1.0,1.0); // set initial color
      glBindTexture(GL_TEXTURE_2D, EnemyTex); // bind texture

      glPushMatrix();
       glTranslatef(xPosE,yPosE,zPosE);   // position of the object
       glRotatef(rotateXE,1.0,0.0,0.0); // rotate around x axis
       glRotatef(rotateYE,0.0,1.0,0.0); // rotate around y axis
       glRotatef(rotateZE,0.0,0.0,1.0); // rotate around z axis
       glScalef(xSizeE,ySizeE,1);        // scale object

       glBegin(GL_POLYGON);

          glTexCoord2f(0.0,0.0);
          glVertex3f(1.0,1.0,0.0);

          glTexCoord2f(1.0,0.0);
          glVertex3f(-1.0,1.0,0.0);

          glTexCoord2f(1.0,1.0);
          glVertex3f(-1.0,-1.0,0.0);

          glTexCoord2f(0.0,1.0);
          glVertex3f(1.0,-1.0,0.0);

       glEnd();
      glPopMatrix();
    }
}

void Enemy::placeEnemy(float x, float y, float z)
{
    xPosE =x;   // placing x
    yPosE =y;   // placing y
    zPosE =z;   // placing z
}
