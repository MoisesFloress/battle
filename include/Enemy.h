#ifndef ENEMY_H
#define ENEMY_H

#include<Model.h>
#include<gl/gl.h>
#include<textureLoader.h>


class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        void drawEnemy();     // draw objects
        void placeEnemy(float, float,float); // place objects

        bool isEnemyLive= true; //status of the objects
        GLuint EnemyTex;      // handle Texture


        float xPosE;             //placing objects on x
        float yPosE;             //placing objects on y
        float zPosE;             //placing objects on z

        float xSizeE;            // for scaling x
        float ySizeE;            // for scaling y

        float rotateXE;
        float rotateYE;
        float rotateZE;


    protected:

    private:

    protected:

    private:
};

#endif // ENEMY_H
