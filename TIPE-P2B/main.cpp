//
//  main.cpp
//  Geometry
//
//  Created by Olivier Partensky on 10/06/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

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


#include <GLUT/glut.h>
#include <SDL.h>
//#include <GLUT/GLUT.h>


GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;


void display(void);
void reshape(int x, int y);


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(350,350);
    glutCreateWindow("Solid Sphere");
    xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void display(void)
{

    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0,0.0,-5.0);
    // Red color used to draw.
    glColor3f(0.9, 0.3, 0.2);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a sphere.
    glutWireSphere(radius,20,20);
    // Flush buffers to screen

    glFlush();
    // sawp buffers called because we are using double buffering
   // glutSwapBuffers();
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering

    SDL_Event ev;
    while (SDL_WaitEventTimeout(&ev, 15)) {
        switch (ev.type) {
            case SDL_KEYDOWN:
//                    std::cout << &ev.key << std::endl;
//                std::cout << ev.key.keysym.sym << std::endl;
                switch (ev.key.keysym.sym) {
                    case SDLK_LEFT:
                        glTranslated(-1, 0, 0);
                        break;
                    case SDLK_RIGHT:
                        glTranslated(1, 0, 0);
                        break;
                    case SDLK_UP:
                        glTranslated(0, 0, 1);
                        break;
                    case SDLK_DOWN:
                        glTranslated(0, 0, -1);
                        break;
                    default:
                        break;
                }
                break;
            case SDL_QUIT:
//                open = false;
//                std::cout << "The program should end now." << std::endl;
                break;
        }
    }
}
