//
//  main.cpp
//  ex1
//
//  Created by Administrador on 16/08/2018.
//  Copyright © 2018 Administrador. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

void Draw() {
    // clean windows and set background color
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Change color
    glColor3f(0.0f, 0.0f, 0.0f);
    
    // Draw triangles
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0, 0.5, 0);
        glVertex3f(0.5, -0.5, 0);
    glEnd();
    
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(1, 1.5, 1);
        glVertex3f(1.5, 0.5, 1);
    glEnd();

    
    glFlush();
}

void initScreen() {
    glMatrixMode(GL_PROJECTION);
    //gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    //GLKMatrix4MakeOrtho(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(10, 10);
    
    glutCreateWindow("Exemplo 00 - Triangulos");
    glutDisplayFunc(Draw);
    
    initScreen();
    
    glutMainLoop();
    
}
