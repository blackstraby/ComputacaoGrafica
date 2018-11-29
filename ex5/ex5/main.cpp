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

void Desenha(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    
    
    glColor3f(0.0f, 0.0f, 1.0f);
    
    //Frente
    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3d(0.5, -0.5, -0.5);
        glVertex3d(0.5, 0.5, -0.5);
        glVertex3d(-0.5, 0.5, -0.5);
        glVertex3d(-0.5, -0.5, -0.5);
    glEnd();
    
    //Traseira
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3d(0.5, -0.5, 0.5);
        glVertex3d(0.5, 0.5, 0.5);
        glVertex3d(-0.5, 0.5, 0.5);
        glVertex3d(-0.5, -0.5, 0.5);
    glEnd();
    
    //Dianteira
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3d(0.5, -0.5, -0.5);
        glVertex3d(0.5, 0.5, -0.5);
        glVertex3d(0.5, 0.5, 0.5);
        glVertex3d(0.5, -0.5, 0.5);
    glEnd();
    
    //Direita
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3d(0.5, -0.5, -0.5);
        glVertex3d(0.5, 0.5, -0.5);
        glVertex3d(0.5, 0.5, 0.5);
        glVertex3d(0.5, -0.5, 0.5);
    glEnd();
    
    //Esquerda
    glBegin(GL_POLYGON);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3d(-0.5, -0.5, 0.5);
        glVertex3d(-0.5, 0.5, 0.5);
        glVertex3d(-0.5, 0.5, -0.5);
        glVertex3d(-0.5, -0.5, -0.5);
    glEnd();
    
    //Topo
    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3d(0.5, 0.5, 0.5);
        glVertex3d(0.5, 0.5, -0.5);
        glVertex3d(-0.5, 0.5, -0.5);
        glVertex3d(-0.5, 0.5, 0.5);
    glEnd();
    
    //Base
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3d(0.5, -0.5, -0.5);
        glVertex3d(0.5, -0.5, 0.5);
        glVertex3d(-0.5, -0.5, 0.5);
        glVertex3d(-0.5, -0.5, -0.5);
    glEnd();
    
    glFlush();        //OpenGL
    glutSwapBuffers(); //Glut
}

void Movimento(int key, int x, int y) {
    
    switch (key) {
        case GLUT_KEY_RIGHT:
            rotate_y += 5;

            break;
        case GLUT_KEY_LEFT:
            rotate_y -= 5;
            
            break;
        case GLUT_KEY_UP:
            rotate_x += 5;
            
            break;
        case GLUT_KEY_DOWN:
            rotate_x -= 5;
            
            break;
            
        default:
            break;
    }
    
    glutPostRedisplay();
    
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    
    //glutInitWindowPosition(10, 10);
    glutCreateWindow("Exemplo 05 - Cubos Movimento 3D");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(Desenha);
    glutSpecialFunc(Movimento);
    
   // glutReshapeFunc(AlteraTamanhoJanela);
    
   // glutTimerFunc(33, Timer, 1);
   // Inicializa();
    
    glutMainLoop();
}
