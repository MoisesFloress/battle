#include "Inputs.h"
#include <player.h>
#include <objects.h>
#include <Battle.h>

Inputs::Inputs()
{
    //ctor
   prev_Mouse_X =0;
   prev_Mouse_Y =0;
   Mouse_Translate=0;
   Mouse_Roatate=0;
}

Inputs::~Inputs()
{
    //dtor
}
void Inputs::keyEnv(parallax* plx, float speed, objects* obj, Battle* um)
{

    switch(wParam)
    {
        case VK_LEFT:
         //   plx->Xmin -=speed;
         //   plx->Xmax -=speed;
          //  plx->scroll(true,"left",0.00005);
            break;

        case VK_RIGHT:
           // plx->Xmin +=speed;
          //  plx->Xmax +=speed;
          //  plx->scroll(true,"right",0.00005);
            break;

         case VK_UP:
           // plx->Ymin -=speed;
           // plx->Ymax -=speed;
            um->monsterattack();
            um->playerdeath(obj);
            break;

        case VK_DOWN:
           // plx->Ymin +=speed;
          //  plx->Ymax +=speed;
                for (int i = 0; i < 4; i++)
          {
              obj[i].isObjectLive = false;
          }




            break;

        case VK_ADD:

            plx->parallaxInit("images/churchbackground.jpg");
            break;

        case VK_MULTIPLY:
            plx->parallaxInit("images/hospitalbackground.jpg");
            break;

        case VK_DIVIDE:
            plx->parallaxInit("images/mansionbackground.jpg");
            break;

        case VK_SUBTRACT:
            plx->parallaxInit("images/realclock.jpg");
            break;

    }
}


void Inputs::keyPressed(Model* Mdl)
{
    switch(wParam)
    {
    case VK_LEFT:
        Mdl->RotateX += 1.0;
        break;

    case VK_RIGHT:
        Mdl->RotateX -=1.0;
        break;

    case VK_DOWN:
        Mdl->RotateY -=0;
        break;

    case VK_UP:
        Mdl->RotateY +=0;
        break;

    case VK_ADD:
//Mdl->Zoom +=1.0;
        break;

    case VK_SUBTRACT:
       // Mdl->Zoom -=1.0;
        break;
    }
}

void Inputs::keyUp(player* ply)
{
    ply->actionTrigger =0;

    switch(wParam)
    {
       default:break;
    }
}


void Inputs::keyPressed(player* ply)
{
    switch(wParam)
    {


     case VK_LEFT:
       ply->actionTrigger =3;


        break;

    case VK_RIGHT:
       ply->actionTrigger =1;

        break;

    case VK_DOWN:
    ply->actionTrigger =0;

        break;

    case VK_UP:
    ply->actionTrigger =2;


        break;

    case VK_ADD:

        break;

    case VK_SUBTRACT:

        break;
    }
}


void Inputs::keyUP()
{
  switch (wParam)
            {
                default:
                break;
            }
}

void Inputs::mouseEventDown(Model *Model, double x,double y)
{
        prev_Mouse_X =x;
        prev_Mouse_Y =y;

   switch (wParam)
            {
                case MK_LBUTTON:
                        Mouse_Roatate = true;
                    break;

                case MK_RBUTTON:
                     Mouse_Translate =true;
                    break;
                case MK_MBUTTON:

                    break;

                default:
                    break;
            }
}

 void Inputs::mouseEventUp()
 {
    Mouse_Translate =false;
    Mouse_Roatate =false;
 }

void Inputs::mouseWheel(Model *Model,double Delta)
{
   // Model->Zoom += Delta/100;
}

void Inputs::mouseMove(Model *Model,double x,double y)
{

      if(Mouse_Translate)
      {
       Model->Xpos += (x-prev_Mouse_X)/100;
       Model->Ypos -= (y-prev_Mouse_Y)/100;

       prev_Mouse_X =x;
       prev_Mouse_Y =y;
      }

      if(Mouse_Roatate)
      {
        Model->RotateY += (x-prev_Mouse_X)/3;
        Model->RotateX += (y-prev_Mouse_Y)/3;

        prev_Mouse_X =x;
        prev_Mouse_Y =y;
      }

}

