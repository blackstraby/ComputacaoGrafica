//
//  main.cpp
//  ex5
//
//  Created by Jonas Gomes on 29/11/2018.
//  Copyright © 2018 Jonas Gomes. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

double rotate_x = 0;
double rotate_y = 0;

//Tamanho e posicao do quadro
GLfloat x1 = 100.0f;
GLfloat y1 = 100.0f;
GLfloat rsize = 50.0f;

//Quanto vc quer que a figura desloca
GLfloat xstep = 2.0f;
GLfloat ystep = 2.0f;

//Largura da Janela
GLfloat windowWidth;
GLfloat windowHeigth;

float ver[8][3] =
{
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};

GLfloat color[8][3] =
{
    {0.0,0.0,0.0},
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {1.0,0.0,1.0},
    {1.0,1.0,1.0},
    {0.0,1.0,1.0},
};

void quad(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glVertex3fv(ver[a]);
    
    glColor3fv(color[b]);
    glVertex3fv(ver[b]);
    
    glColor3fv(color[c]);
    glVertex3fv(ver[c]);
    
    glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();
}


void colorcube()
{
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);
}


void Desenha(void){
    glClearColor( 0, 0, 0, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 0.1, 100 );
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    //Aqui muda a visualizacao inicial do cubo
    //Comente para entrar dentro do cubo
    gluLookAt(
     4, 4, 3,
     0, 0, 0,
     0, 0, 1
     );
    
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    
    
    glColor3f(0.0f, 0.0f, 1.0f);
    
    colorcube();

    
    glFlush();        //OpenGL
    glutSwapBuffers(); //Glut
}

void Movimento(int key, int x, int y) {
    
    switch (key) {
        case GLUT_KEY_RIGHT:
            rotate_y += 10;
            
            break;
        case GLUT_KEY_LEFT:
            rotate_y -= 10;
            
            break;
        case GLUT_KEY_UP:
            rotate_x += 10;
            
            break;
        case GLUT_KEY_DOWN:
            rotate_x -= 10;
            
            break;
            
        default:
            break;
    }
    
    glutPostRedisplay();
    
}


void Timer(int value) { 
    //Muda a direcao esquerda/direita
    if (x1 > windowWidth-rsize || x1 < 0){
        xstep += 2.0f;
        ystep += 2.0f;
        xstep = -xstep;
    }
    
    //Muda a direcao cima/baixo
    if (y1 > windowHeigth-rsize || y1 < 0){
        ystep = -ystep;
    }
    
    
    if (x1 > windowWidth-rsize)
        x1 = windowWidth-rsize-1;
    
    if (y1 > windowHeigth-rsize)
        y1 = windowHeigth-rsize-1;
    
    x1 += xstep;
    y1 += ystep;
    
    glutPostRedisplay();
    glutTimerFunc(33, Timer, 1);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    
    //glutInitWindowPosition(10, 10);
    glutCreateWindow("Trabalho 02 - Cubos Com Faces 3D");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(Desenha);
    glutSpecialFunc(Movimento);
    
    glutTimerFunc(33, Timer, 1);

    glutMainLoop();
}
