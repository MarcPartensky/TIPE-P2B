//
//  main.cpp
//  Geometry
//
//  Created by Olivier Partensky on 10/06/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#define GL_SILENCE_DEPRECATION // to silence warnings

#ifdef __APPLE__ // for compatibility with apple when including GLUT
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES // for PI

#define SPACEBAR 32 // for spacebar detection

const int n = 2000; // number of sand grains
bool showCout = false; // showing cout or not (useful when debugging)

#include <iostream> // for std
#include <stdlib.h> // for random
#include <math.h> // for PI

#include <GLUT/glut.h> // for opengl manipulation
#include <glm/glm.hpp> // for matrix operations

#include "SandBox.cpp" // for the sand
#include "Camera.cpp" // for camera
#include "Board.cpp" // for board

GLfloat cameraRotation[3];
GLfloat cameraPosition[3];

Camera camera;
SandBox sandBox;
Board board;

int mouse[2];

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidSphere(0.5f, 50, 60);
    glutSwapBuffers();
}

static void displayFunc(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera.look();
    sandBox.show();
    board.show();
    glFlush();
}

void idleFunc(void)
{
    displayFunc();
    sandBox.update();
    board.collideWithSand(sandBox);
}

void reshapeFunc(int x, int y)
{
    // Used when the window is reshaped
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    camera.eye[0] = 30;
    camera.eye[1] = 50; // Initial position in the scene
    camera.eye[2] = 150; // Initial position in the scene
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);  //Use the whole window for rendering
}

void mouseFunc(int button, int state, int x, int y) {
    // std::cout << "mouseFunc: " << button << ',' << state << ',' << x << ',' << y << std::endl;
}

void motionFunc(int x, int y) {
    // std::cout << "motionFunc: " << x << ',' << y << std::endl;
}

void passiveMotionFunc(int x, int y) {
    // std::cout << "passiveMotionFunc: " << x << ',' << y << std::endl;
    mouse[0] = x;
    mouse[1] = y;
}

void keyboardFunc(unsigned char key, int ix, int iy) {
    // std::cout << key << std::endl;
    switch (key) {
        case 'e':
            showCout = !showCout;
            if (showCout) {
                std::cout << "showing cout" << std::endl;
            } else {
                std::cout << "not showing cout" << std::endl;
            }
            break;
        case 'a':
            camera.eye.x-=1;
            break;
        case 'd':
            camera.eye.x+=1;
            break;
        case 'w':
            camera.eye.z-=1;
            break;
        case 's':
            camera.eye.z+=1;
            break;
        case SPACEBAR:
            camera.eye.y+=1;
            break;
        case 'z':
            camera.eye.y-=1;
            break;
        case 'x':
            board.angle+=1;
            break;
        case 'c':
            board.angle-=1;
            break;
        case 27: // escape => quit
            exit(0);
            break;
    }
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(2560, 1600);
    glutCreateWindow("Sphere Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glClearColor(0.5, 0.7, 1.0, 0.0);
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    glutIdleFunc(idleFunc);
    glutKeyboardFunc(keyboardFunc);
    glutMouseFunc(mouseFunc);
    glutMotionFunc(motionFunc);
    glutPassiveMotionFunc(passiveMotionFunc);
    glutMainLoop();

    return 0;
}