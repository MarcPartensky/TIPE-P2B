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
// #include "SDL2/SDL.h"
#include <glm/glm.hpp>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define SPACEBAR 32

// #ifdef __APPLE__
// #include <OpenGL/gl.h>
// #else
// #include <GL/gl.h>
// #endif

// #include "SimpleBall.hpp"
// #include "Sand.hpp"
// #include "SandBox.hpp"
// #include "SandGrain.hpp"
#include "Camera.hpp"

#include <stdlib.h> // for rand

const int n = 1000; // number of sand grains

// GLfloat xRotated, yRotated, zRotated;

GLfloat cameraRotation[3];
GLfloat cameraPosition[3];

Camera camera;

int mouse[2];

GLfloat mat_ambient_color[] = { 0.7f, 0.7f, 0.7f, 1.0f };

// glm::vec3 eye(0.0f, 0.0f, 1.0f);
// glm::vec3 center(0.0f, 0.0f, 0.0f);
// glm::vec3 up(0.0f, 1.0f, 0.0f);
// Camera camera(eye, center, up);

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
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    
    // changing in transformation matrix.
    // rotation about X axis
    
    // glRotatef(ax, 0, 0, 0.0);
    // rotation about Y axis
    // glRotatef(ay, 0.0, 0.0, 0.0);
    // rotation about Z axis
    // glRotatef(az, 0.0, 0.0, 0.0);
    // scaling transfomation
    // glScalef(1.0, 1.0, 1.0);
    // built-in (glut library) function , draw you a sphere.

    // glLoadIdentity();
    // float x = camera.center.x;
    // float y = camera.center.y;
    // float z = camera.center.z;
    glTranslatef(camera.center.x,camera.center.y,camera.center.z);

    glColor3f(1.0f, 1.0f, 0.0f);
    glutSolidSphere(0.5f, 50, 60);

    int s = 200;
    glColor3f(0, 0, 0);
    glutSolidCube(s);

    int n = 6;
    int p = 5;
    for (int x=-n; x<=n; x++) {
        for (int z=-n; z<=n; z++) {
            for (int y=-n; y<=n; y++) {
                float r = float(rand())/RAND_MAX/2+0.5;
                glColor3f(r, r, 0);
                glPushMatrix();
                glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
                glTranslatef(p*x, p*y , p*z);
                glutSolidSphere(2.0, 20, 20);
                // glTranslatef(-p*x, -p*y , -p*z);
                glPopMatrix();
            }
        }    
    }



    // gluLookAt(
    //     camera.eye.x,
    //     camera.eye.y,
    //     camera.eye.z,
    //     camera.center.x,
    //     camera.center.y,
    //     camera.center.z,
    //     camera.up.x,
    //     camera.up.y,
    //     camera.up.z
    // );
    
    // glutSwapBuffers();
    glFlush();
    
}

void reshapeFunc(int x, int y)
{
    // Used when the window is reshaped
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    std::cout << "reshaping" << std::endl;
    std::cout << x << y << std::endl;
    camera.center[2] = -10; // Initial position in the scene
    // glTranslatef(camera.center.x, camera.center.y, camera.center.z);
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);  //Use the whole window for rendering
}

void idleFunc(void)
{
    // yRotated += 0.1;
    displayFunc();
}

void mouseFunc(int button, int state, int x, int y) {
    // std::cout << "mouseFunc: " << button << ',' << state << ',' << x << ',' << y << std::endl;
}

void motionFunc(int x, int y) {
    // std::cout << "motionFunc: " << x << ',' << y << std::endl;
}

void passiveMotionFunc(int x, int y) {
    // std::cout << "passiveMotionFunc: " << x << ',' << y << std::endl;
    // cameraRotation[0] += cos(mouse[0] - x);
    // cameraRotation[1] += mouse[1] - y;
    mouse[0] = x;
    mouse[1] = y;
}

void keyboardFunc(unsigned char key, int ix, int iy) {
    std::cout << key << std::endl;
    switch (key) {
        case 'a':
            camera.center.x+=1;
            break;
        case 'd':
            camera.center.x-=1;
            break;
        case 'w':
            camera.center.z+=1;
            break;
        case 's':
            camera.center.z-=1;
            break;
        case SPACEBAR:
            std::cout << "spacebar rn" << std::endl;
            camera.center.y-=1;
            break;
        case 'z':
            camera.center.y+=1;
            break;
        case 27: // escape => quit
            exit(0);
            break;
    }
    // std::cout << '(' << camera.center.x << ',' << camera.center.y << ',' << camera.center.z << ')' << std::endl;
}



int main(int argc, char **argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    // glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    // window size
    glutInitWindowSize(2560, 1600);
    // create the window
    glutCreateWindow("Sphere Rotating Animation");
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // cameraRotation[0] = 0;
    // cameraRotation[1] = 0;
    // cameraRotation[2] = 0;

    // glm::vec3 eye(0.0f, 0.0f, 1.0f);
    // glm::vec3 center(0.0f, 0.0f, 0.0f);
    // glm::vec3 up(0.0f, 1.0f, 0.0f);
    // Camera camera(eye, center, up);

    glClearColor(1.0, 1.0, 1.0, 0.0);
    //Assign  the function used in events
    glutDisplayFunc(display);
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
