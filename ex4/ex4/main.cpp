//
//  main.cpp
//  ex4
//
//  Created by Jonas Gomes on 08/11/2018.
//  Copyright © 2018 Jonas Gomes. All rights reserved.
//


#include <iostream>
#include <stdlib.h>
#include <fstream>

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

//Tamanho e posicao do quadro
GLfloat x1 = 100.0f;
GLfloat y1 = 100.0f;
GLfloat rsize = 50.0f;

//Quanto vc quer que a figura desloca
GLfloat xstep = 5.0f;
GLfloat ystep = 10.0f;

//Largura da Janela
GLfloat windowWidth;
GLfloat windowHeigth;

void Desenha(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    
    glBegin(GL_QUADS);
    
    glVertex2i(x1, y1+rsize);
    
    glVertex2i(x1, y1);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(x1+rsize, y1);
    glVertex2i(x1+rsize, y1+rsize);
    
    glEnd();
    //glFlush();        //OpenGL
    glutSwapBuffers(); //Glut
}

void Timer(int value) {
    //Muda a direcao esquerda/direita
    if (x1 > windowWidth-rsize || x1 < 0)
        xstep = -xstep;

    //Muda a direcao cima/baixo
    if (y1 > windowHeigth-rsize || y1 < 0)
        ystep = -ystep;
    
    if (x1 > windowWidth-rsize)
        x1 = windowWidth-rsize-1;
    
    if (y1 > windowHeigth-rsize)
        y1 = windowHeigth-rsize-1;
    
    x1 += xstep;
    y1 += ystep;
    
    glutPostRedisplay();
    glutTimerFunc(33, Timer, 1);
}

void Inicializa(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void AlteraTamanhoJanela(GLsizei w,GLsizei h) {
    if (h==0) h=1;
    if (w==0) w=1;
    
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(h <= w) {
        windowHeigth = 250.0f * h/w;
        windowWidth = 250.0f;
    } else {
        windowHeigth = 250.0f;
        windowWidth = 250.0f * h/w;
    }
    
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeigth);
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitWindowPosition(10, 10);
    glutCreateWindow("Exemplo 04 - Cubos Movimento");
 
    glutDisplayFunc(Desenha);
    
    glutReshapeFunc(AlteraTamanhoJanela);
    
    glutTimerFunc(33, Timer, 1);
    Inicializa();
    
    glutMainLoop();
}
