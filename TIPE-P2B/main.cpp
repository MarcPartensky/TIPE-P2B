//
//  main.cpp
//  Geometry
//
//  Created by Olivier Partensky on 10/06/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#define GL_SILENCE_DEPRECATION

// Maybe useful who knows
//#include <stdio.h>
//#include <stdbool.h>
//#define GL_GLEXT_PROTOTYPES
//
//#include <iostream>
//
//#include <GLUT/GLUT.h>
//#include "SceneOpenGL.hpp"
//
//
//int main(int argc, const char * argv[]) {
//    SceneOpenGL scene("main", 800, 600);
//    bool success = scene.init();
//    if (!success) {
//        std::cout << "Failed" << std::endl;
//        return EXIT_FAILURE;
//    }
//    //    vector<double> position(3, 0);
//    //    vector<double> rotation(3, 0);
//
//    scene.open = true;
//    SDL_Event ev;
//    while (scene.open) {
//        while (SDL_WaitEventTimeout(&ev, 15)) {
//            switch (ev.type) {
//                case SDL_KEYDOWN:
////                    std::cout << &ev.key << std::endl;
//                    std::cout << ev.key.keysym.sym << std::endl;
//                    switch (ev.key.keysym.sym) {
//                        case SDLK_LEFT:
//                            glTranslated(-1, 0, 0);
//                            break;
//                        case SDLK_RIGHT:
//                            glTranslated(1, 0, 0);
//                            break;
//                        case SDLK_UP:
//                            glTranslated(0, 0, 1);
//                            break;
//                        case SDLK_DOWN:
//                            glTranslated(0, 0, -1);
//                            break;
//                        default:
//                            break;
//                    }
//                    break;
//                case SDL_QUIT:
//                    scene.open = false;
//            }
//        }
//        // scene.clear();
//        scene.show();
//
//        // scene.swap();
//    }
//    return 0;
//}


#include <iostream>
#include <GLUT/glut.h>
//  #include <SDL.h>
#include "SDL2/SDL.h"
//#include <glm/glm.hpp>

const int n = 1000; // number of sand grains

double x=0, y=0, z=-10;

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

// #include "SimpleBall.hpp"
// #include "Sand.hpp"
// #include "SandBox.hpp"
// #include "SandGrain.hpp"


//
//GLfloat xRotated, yRotated, zRotated;
//GLdouble radius=1;
//
//void display(void);
//void reshape(int x, int y);
//
//
//int main (int argc, char **argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(2560,1600);
//    glutCreateWindow("Solid Sphere");
//    xRotated = yRotated = zRotated = 30.0;
//    xRotated=43;
//    yRotated=50;
//    std::cout << "test" << std::endl;
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    glutMainLoop();
//    return 0;
//}
//
//void display(void)
//{
//
//    glMatrixMode(GL_MODELVIEW);
//    // clear the drawing buffer.
//    glClear(GL_COLOR_BUFFER_BIT);
//    // clear the identity matrix.
//    glLoadIdentity();
//    // traslate the draw by z = -4.0
//    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
////    glTranslatef(0.0,1,-5.0);
//    // Red color used to draw.
//    glColor3f(0.9, 0.3, 0.2);
//    // changing in transformation matrix.
//    // rotation about X axis
//    glRotatef(xRotated,1.0,0.0,0.0);
//    // rotation about Y axis
//    glRotatef(yRotated,0.0,1.0,0.0);
//    // rotation about Z axis
//    glRotatef(zRotated,0.0,0.0,1.0);
//    // scaling transfomation
//    glScalef(1.0,1.0,1.0);
//    // built-in (glut library) function , draw you a sphere.
//    glutWireSphere(radius,20,20);
////    glutSolidSphere(radius, 20, 20);
//    // Flush buffers to screen
//
//    glFlush();
//    // sawp buffers called because we are using double buffering
//   // glutSwapBuffers();
//}
//
//void reshape(int x, int y)
//{
//    if (y == 0 || x == 0) return;
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
//    glMatrixMode(GL_MODELVIEW);
//    glViewport(0,0,x,y);  //Use the whole window for rendering
//
//    SDL_Event ev;
//    while (SDL_WaitEventTimeout(&ev, 15)) {
//        switch (ev.type) {
//            case SDL_KEYDOWN:
////                    std::cout << &ev.key << std::endl;
//                std::cout << ev.key.keysym.sym << std::endl;
//                switch (ev.key.keysym.sym) {
//                    case SDLK_LEFT:
//                        glTranslated(-1, 0, 0);
//                        break;
//                    case SDLK_RIGHT:
//                        glTranslated(1, 0, 0);
//                        break;
//                    case SDLK_UP:
//                        glTranslated(0, 0, 1);
//                        break;
//                    case SDLK_DOWN:
//                        glTranslated(0, 0, -1);
//                        break;
//                    default:
//                        break;
//                }
//                break;
//            case SDL_QUIT:
////                open = false;
//                std::cout << "The program should end now." << std::endl;
//                break;
//        }
//    }
//}


GLfloat xRotated, yRotated, zRotated;


int mouseBuffer[2];
// mouseBuffer[0] = 0;
// mouseBuffer[1] = 0;

void redisplayFunc(void)
{

    // std::cout << "Ce code est exécuté" ;

    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    
    // Red color used to draw.
    glColor3f(0.8, 0.2, 0.1);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated, 50.0, 50.0, 0.0);
    // rotation about Y axis
    glRotatef(yRotated, 0.0, 0.0, 0.0);
    // rotation about Z axis
    glRotatef(zRotated, 0.0, 0.0, 0.0);
    // scaling transfomation
    glScalef(1.0, 1.0, 1.0);
    // built-in (glut library) function , draw you a sphere.

    // glTranslatef(5,0,0);
    glutSolidSphere(2, 20, 50);
    // glTranslatef(-10,0,0);
    // glutSolidSphere(2, 20, 50);
    // glTranslatef(5,0,0);
    // Flush buffers to screen
    

    glFlush();
    
}

void reshapeFunc(int x, int y)
{
    //if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(x, y, z);
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);  //Use the whole window for rendering
}

void idleFunc(void)
{
    yRotated += 0.1;
    redisplayFunc();
}

void mouseFunc(int button, int state, int x, int y) {
    std::cout << "mouseFunc: " << button << ',' << state << ',' << x << ',' << y << std::endl;
}

void motionFunc(int x, int y) {
    std::cout << "motionFunc: " << x << ',' << y << std::endl;
}

void passiveMotionFunc(int x, int y) {
    std::cout << "passiveMotionFunc: " << x << ',' << y << std::endl;
    ax = mouseBuffer[0] - x
    ay = mouse
    mouseBuffer[0] = x;
    mouseBuffer[1] = y;
}

void keyboardFunc(unsigned char key, int ix, int iy) {
    switch (key) {
        case 'a':
            x+=1;
            break;
        case 'd':
            x-=1;
            break;
        case 'w':
            z+=1;
            break;
        case 's':
            z-=1;
            break;
        case 27: // escape => quit
            exit(0);
            break;
    }
    std::cout << '(' << x << ',' << y << ',' << z << ')' << std::endl;
}



int main(int argc, char **argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // window size
    glutInitWindowSize(2560, 1600);
    // create the window
    glutCreateWindow("Sphere Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    xRotated = yRotated = zRotated = 30.0;
    xRotated = 33;
    yRotated = 40;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //Assign  the function used in events
    glutDisplayFunc(redisplayFunc);
    glutReshapeFunc(reshapeFunc);
    glutIdleFunc(idleFunc);
    glutKeyboardFunc(keyboardFunc);
    glutMouseFunc(mouseFunc);
    glutMotionFunc(motionFunc);
    glutPassiveMotionFunc(passiveMotionFunc);
    //Let start glut loop
    glutMainLoop();

    return 0;
}
