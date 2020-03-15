//
//  SceneOpenGL.hpp
//  Geometry
//
//  Created by Marc Partensky on 13/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#ifndef SceneOpenGL_hpp
#define SceneOpenGL_hpp

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <string>

#include "SDL.h"
// #include <SDL2/SDL.h>
// #include "frameworks/SDL2.framework/Versions/Current/Headers/SDL.h"
//#include "Shader.h" // Shaders

class SceneOpenGL
{
    // Methods
public:
    SceneOpenGL(std::string title, int width, int height);
    ~SceneOpenGL();
    bool init();
    void main();
    void show();
    void clear();
    void swap();
    void draw();
    
    // Attributes
public:
    std::string title;
    int width;
    int height;
    bool open;
protected:
    SDL_Window* window;
    SDL_GLContext context;
    SDL_Event event;
};


#endif /* SceneOpenGL_hpp */
