#include "Fonts.h"
#include <cstring>

Fonts::Fonts()
{
    //ctor
    zoom = -4.0;
    xPos = 1.0;
    yPos = 0.5;
    cCnt = 0;
    zPos = 0;
}

Fonts::~Fonts()
{
    //dtor
}
void Fonts::initFonts(char* fileName)
{
    ftex->binder();
    ftex->bindTexture(fileName);


}

void Fonts::buildFonts(char* str)
{
    for(int i = 0; i <  strlen(str); i++)
    {

        switch(str[i])
        {
      case 'a':

          c[cCnt].xMin = 0;
          c[cCnt].xMax = 1.0/13;
        //  c[cCnt].yMin = 3.0;
       //  c[cCnt].yMax = 5.0;


        break;

         case 'A':

          c[cCnt].xMin = 0;
          c[cCnt].xMax = 1.0/13;
         // c[cCnt].yMin = ??
        //  c[cCnt].yMax = ??


        break;
        // have 75 cases depending on your font image
        }
        cCnt++;
    }
}

void Fonts::drawFont(int i)
{
    ftex->binder();
  //  glPushMatrix();
    glBegin(GL_QUADS);

      glTexCoord2f(c[i].xMin, 1.0);
    glVertex3f(0.0,0.0,0.0);

    glTexCoord2f(c[i].xMax, 1.0);
    glVertex3f(1.0/13,1.0,0.0);         // depending on your image

    glTexCoord2f(c[i].xMax, 0.0);
    glVertex3f(1/13,1.0,0.0);

    glTexCoord2f(c[i].xMin, 1.0);
    glVertex3f(0.0,1.0,0.0);

    glEnd();


   // glPopMatrix();
}
