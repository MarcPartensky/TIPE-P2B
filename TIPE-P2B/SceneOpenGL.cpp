//
//  SceneOpenGL.cpp
//  Geometry
//
//  Created by Marc Partensky on 13/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#include "SceneOpenGL.hpp"

#include <iostream>


SceneOpenGL::SceneOpenGL(std::string title, int width, int height) {
    mTitle = title;
    mWidth = width;
    mHeight = height;
}

SceneOpenGL::~SceneOpenGL () {
    SDL_GL_DeleteContext(mContext);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

bool SceneOpenGL::init() {
    // Initializing SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
         std::cout << stderr << std::endl;
         std::cout << "Sdl couldn't be initialized." << std::endl;
         std::cout << SDL_GetError() << std::endl;
         SDL_Quit();
         return false;
     }

    // Creating Window
    mWindow = SDL_CreateWindow("main",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    mWidth, mHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!mWindow) {
        std::cout << stderr << std::endl;
        std::cout << "The window couldn't be created." << std::endl;
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // Creating context
    mContext = SDL_GL_CreateContext(mWindow);
    if (!mContext) {
        std::cout << stderr << std::endl;
        std::cout << "The context couldn't be created." << std::endl;
        std::cout << SDL_GetError() << std::endl;
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        return false;
    }
    
    // OpenGL Version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    
    // Double Buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    return true;
}


void SceneOpenGL::main() {
//    vector<double> position(3, 0);
//    vector<double> rotation(3, 0);

    mOpen = true;
    SDL_Event ev;
    while (mOpen) {
        while (SDL_WaitEventTimeout(&ev, 15)) {
            switch (ev.type) {
                case SDL_QUIT:
                    mOpen = false;
            }
        }
        show();
    }
}


void SceneOpenGL::draw() {
//    Shader shaderBasique("shaders/basique2D.vert", "shaders/basique2D.frag");
//    shaderBasique.charger();
//    glUseProgram(shaderBasique.getProgramID());
    
    
    // verticies
    float vs1[] = {0.0, 0.0,   0.5, 0.0,   0.0, 0.5,          // Triangle 1
                        -0.8, -0.8,   -0.3, -0.8,   -0.8, -0.3};   // Triangle 2
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vs1);
    glEnableVertexAttribArray(0);
    
    // colors
    float colors[] = {0.0, 204.0 / 255.0, 1.0,    0.0, 204.0 / 255.0, 1.0,    0.0, 204.0 / 255.0, 1.0};
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, colors);
    glEnableVertexAttribArray(1);
    
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}

void SceneOpenGL::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void SceneOpenGL::swap() {
    SDL_GL_SwapWindow(mWindow);
}

void SceneOpenGL::show() {
    clear();
    draw();
    swap();
}
