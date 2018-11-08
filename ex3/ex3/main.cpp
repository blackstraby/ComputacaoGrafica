//
//  main.cpp
//  ex3
//
//  Created by Jonas Gomes on 01/11/2018.
//  Copyright © 2018 Jonas Gomes. All rights reserved.
//


#include <iostream>
#include <stdlib.h>
#include <fstream>

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void Desenha(void) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f,0.0f,0.0f);
    
    glPointSize(3);
    glLineWidth(3);
    
    glBegin(GL_LINE_LOOP);
    glVertex2i(100,150);
    glVertex2i(100, 100);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    
    glVertex2i(150,100);
    glVertex2i(150, 150);
    
    glEnd();
    glFlush();
}

void Inicializa(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void AlteraTamanhoJanela(GLsizei w,GLsizei h) {
    if (h==0) h=1;
    if (w==0) w=1;
    
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(h <= w) {
        gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h/w);
    } else {
        gluOrtho2D(0.0f, 250.0f * w/h, 0.0f, 250.0f);
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Exemplo 03 - Janelas");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    
    glutMainLoop();
}

