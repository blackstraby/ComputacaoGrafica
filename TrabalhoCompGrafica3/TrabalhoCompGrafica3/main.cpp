#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "SOIL.h"
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <string>

//
//  main.cpp
//  Trabalho Comp Grafica
//
//  Created by Jonas Gomes on 29/11/2018.
//  Copyright © 2018 Jonas Gomes. All rights reserved.
//

using namespace std;


GLfloat tamanhoJanela = 0.5f;

double rotate_y = 0;
double rotate_x = 0;

GLfloat move_y = 0;
GLfloat move_x = 0;

GLfloat xstep = 0.01f;
GLfloat ystep = 0.02f;

GLuint textura[6];

float size = 0.4f;


void desenhaCubo() {

    // Frente
    glBindTexture(GL_TEXTURE_2D, textura[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-size, -size, size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(size, -size, size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(size, size, size);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-size, size, size);
    glEnd();
    
    // Traseira
    glBindTexture(GL_TEXTURE_2D, textura[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-size, -size, -size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-size, size, -size);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(size, size, -size);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(size, -size, -size);
    glEnd();
    
    // Cima
    glBindTexture(GL_TEXTURE_2D, textura[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-size, size, -size);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-size, size, size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(size, size, size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(size, size, -size);
    glEnd();
    
    // Baixo
    glBindTexture(GL_TEXTURE_2D, textura[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(size, -size, -size);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-size, -size, -size);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-size, -size, size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(size, -size, size);
    glEnd();
    
    // Direita
    glBindTexture(GL_TEXTURE_2D, textura[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(size, -size, -size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(size, size, -size);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(size, size, size);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(size, -size, size);
    glEnd();
    
    // Esquerda
    glBindTexture(GL_TEXTURE_2D, textura[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-size, -size, -size);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-size, -size, size);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-size, size, size);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-size, size, -size);
    glEnd();
    
}

void Desenha() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(move_x, move_y, 0.0);
    
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    //CUBO
    desenhaCubo();
    glutSwapBuffers();
}



void timer(int value) {

    if (move_x > tamanhoJanela || move_x < -tamanhoJanela)
        xstep = -xstep;
    
    if (move_y > tamanhoJanela || move_y < -tamanhoJanela)
        ystep = -ystep;
    
    move_x += xstep;
    move_y += ystep;
    rotate_x += 5;
    rotate_y -= 5;
    
    glutPostRedisplay();
    glutTimerFunc(33, timer, 1);

}

void timer2(int value) {
    rotate_x -= 5;
   // rotate_y -= 5;
    
    glutPostRedisplay();
    glutTimerFunc(33, timer2, 1);

}

void Movimento(int key, int x, int y) {
    
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    
    else if (key == GLUT_KEY_F5)
        glutTimerFunc(33, timer, 1);
    
    else if (key == GLUT_KEY_F2)
        glutTimerFunc(33, timer2, 1);
    

    glutPostRedisplay();
    
}


void initTextures() {
    //cima
    textura[0] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/marco.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //baixo
    textura[1] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/if.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //frente
    textura[2] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/dede.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //costa
    textura[3] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/emerson.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //direito
    textura[4] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/sandro.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    
    //esquerdo
    textura[5] = SOIL_load_OGL_texture("/Users/jonasgomes/Desktop/Projetos/ComputacaoGrafica/TrabalhoCompGrafica3/TrabalhoCompGrafica3/images/jabur.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}


void inicializa() {
    glEnable(GL_TEXTURE_2D);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    //glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
  //  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}



int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(480, 480);
    glutCreateWindow("Trabalho - Cubo Movimento com F5 ou F2");
    
    inicializa();
    initTextures();
    
    glutDisplayFunc(Desenha);
    glutSpecialFunc(Movimento);
    
    glutMainLoop();
    
    return 0;
    
}

