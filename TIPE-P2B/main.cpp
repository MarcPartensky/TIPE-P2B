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

#include <iostream>

#include "SceneOpenGL.hpp"


int main(int argc, const char * argv[]) {
    SceneOpenGL scene("main", 800, 600);
    bool success = scene.init();
    if (!success) {
        std::cout << "Failed" << std::endl;
        return EXIT_FAILURE;
    }
    //    vector<double> position(3, 0);
    //    vector<double> rotation(3, 0);

    scene.open = true;
    SDL_Event ev;
    while (scene.open) {
        while (SDL_WaitEventTimeout(&ev, 15)) {
            switch (ev.type) {
                case SDL_QUIT:
                    scene.open = false;
            }
        }
        // scene.clear();
        scene.show();
        // scene.swap();
    }
    return 0;
}
