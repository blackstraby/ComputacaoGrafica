//
//  main.cpp
//  ex2b
//
//  Created by Jonas Gomes on 25/10/2018.
//  Copyright © 2018 Jonas Gomes. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>

#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>

void Inicializa(void){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
}

void Desenha(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Cubo 01
    glPushMatrix();
    
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glScaled(3.0f, 2.0f, 5.0f);
    glutWireCube(1.0);
    glPopMatrix();
    
    //Cubo 02
    glPushMatrix();
    glRotated(25.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(2.0f, 0.0f, 0.0f);
    glScaled(2.0f, 1.0f, 4.0f);
    glutWireCube(1.0);
    glPopMatrix();
    
    //Cubo 03
    glPushMatrix();
    
    glTranslatef(0.0f, 2.0f, 0.0f);
    glScaled(2.0f, 1.0f, 4.0f);
    glutWireCube(1.0);
    glPopMatrix();
    
    //Cubo 04
    glPushMatrix();
    
    glTranslatef(0.0f, -2.0f, 0.0f);
    glScaled(2.0f, 1.0f, 4.0f);
    glutWireCube(1.0);
    glPopMatrix();
    
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("Exemplo 02 - B - Cubos");
    glutDisplayFunc(Desenha);
    
    glMatrixMode(GL_PROJECTION);
    gluPerspective(65.0, 1.0, 1.0, 20);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0f, 0.0f, -10.0f);
    
    Inicializa();
    glutMainLoop();
    
    return 0;
}
