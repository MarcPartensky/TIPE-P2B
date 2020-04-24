//
//  Ball.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 15/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <vector>
#include "SceneOpenGL.hpp"

#define _USE_MATH_DEFINES
#include <math.h>


struct Ball {
public:
//    Ball(glm::vec3 position, float radius, int stacks, int sectors);
    void compute(); // Compute the vertices
    void show(SceneOpenGL scene);
    ~Ball();
protected:
//    glm::vec3 position;
    float radius;
    int stacks;
    int sectors;
    std::vector<float> vertices;
    std::vector<float> normals;
    
    
};

#endif /* Ball_hpp */
