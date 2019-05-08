#include "GLScene.h"
#include <GLLight.h>
#include <Model.h>
#include <Inputs.h>
#include <parallax.h>
#include <player.h>
#include <GL/gl.h>
#include <objects.h>
#include <Battle.h>
#include <Enemy.h>

Model *modelTeapot = new Model();
Inputs *KbMs = new Inputs();
parallax *plx = new parallax();

player *ply = new player();

textureLoader *objtex= new textureLoader();
textureLoader *objtex1= new textureLoader();
objects obj[5];
Battle *um = new Battle();
textureLoader *eviltex = new textureLoader();
textureLoader *eviltex1 = new textureLoader();
Enemy evil[1];

GLScene::GLScene()
{
    //ctor
    screenHeight= GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

   // glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0);

    modelTeapot->modelInit("images/player/player0.png",true);
    plx->parallaxInit("images/battlebackground.jpg");

    ply->playerInit();
    objtex->bindTexture("images/hp.png");
    objtex1->bindTexture("images/hp.png");
    eviltex->bindTexture("images/fl.png");


    for(int i=0;i<1;i++)
        {
        (i<1)?evil[i].EnemyTex = eviltex->tex:evil[i].EnemyTex = eviltex1->tex;
    evil.xPosE = 1;
    evil.yPosE= 1.0;
    evil.ySizeE = 0.5;
        }
    for(int i=0;i<5;i++)
        {
        (i<3)?obj[i].objectTex = objtex->tex:obj[i].objectTex = objtex1->tex;

          // obj[i].rotateZ = (float)(rand()%360);

           obj[i].xPos = i-2;
           obj[i].yPos = -1.8;

           obj[i].ySize=obj[i].xSize= 0.1;
        }
    return true;
}





GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix



   glPushMatrix();
    glScaled(3.33,3.2,1.0);
        plx->drawSquare(screenWidth,screenHeight);
    glPopMatrix();
  //  plx->scroll(true,"right",0.00005);


     glPushMatrix();
  //     modelTeapot->drawModel();
     glTranslated(0,0,modelTeapot->Zoom);
     ply->actions(ply->actionTrigger);
     glPopMatrix();

       for(int i=0;i<4;i++)
     {  //obj[i].rotateZ>=360?obj[i].rotateZ=0:obj[i].rotateZ += 0.5;
        evil[i].drawEnemy();
     }
     for(int i=0;i<4;i++)
     {  //obj[i].rotateZ>=360?obj[i].rotateZ=0:obj[i].rotateZ += 0.5;
        obj[i].drawObjects();
     }


}

GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
   GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
   glViewport(0,0,width,height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0,aspectRatio,0.1,100);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)									// Check For Windows Messages
	{

	    case WM_KEYDOWN:
	        KbMs->wParam = wParam;
	        KbMs->keyPressed(modelTeapot);
	        KbMs->keyEnv(plx, 0.005,obj,um);
	        KbMs->keyPressed(ply);
	    break;

	    case WM_KEYUP:								// Has A Key Been Released?
		{
			KbMs->wParam = wParam;
			KbMs->keyUP();
			KbMs->keyUp(ply);
		break;								// Jump Back
		}

		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(modelTeapot,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(modelTeapot,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(modelTeapot,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KbMs->mouseEventUp();
        break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
             KbMs->mouseMove(modelTeapot, LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
            KbMs->mouseWheel(modelTeapot,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;								// Jump Back
        }
}
}
