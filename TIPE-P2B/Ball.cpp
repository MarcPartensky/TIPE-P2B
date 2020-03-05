//
//  Ball.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 15/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#include "Ball.hpp"





Ball::Ball(glm::vec3 position, float radius, int stacks, int sectors) {
    this->position = position;
    this->radius = radius;
    this->stacks = stacks;
    this->sectors = sectors;
}

void Ball::compute() {
    std::vector<float>().swap(vertices);
    std::vector<float>().swap(normals);
    
    float lengthInv = 1.0f / radius;
    
    float sectorStep = 2*M_PI*sectors;
    float stackStep = M_PI*stacks;
    float stackAngle, sectorAngle;
    float nx, ny, nz;
    float x, y, z, xy;
    float s, t;
    
    for (int i=0; i<stacks; i++) {
        stackAngle = M_PI * stackStep;
        xy = radius * cosf(stackAngle);
        z = radius * sinf(stackAngle);
        
        for (int j=0; j<sectors; j++) {
            sectorAngle = i*sectorStep;
            x = xy * cosf(sectorAngle);
            y = xy * sinf(sectorAngle);
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
            
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);
            
            s = (float)j / sectorCount;
            t = (float)i / stackCount;
            texCoords.push_back(s);
            texCoords.push_back(t);
        }
    }
    
    std::vector<int> indices;
    int k1, k2;
    for(int i = 0; i < stacks; ++i)
    {
        k1 = i * (sectors + 1);     // beginning of current stack
        k2 = k1 + sectors + 1;      // beginning of next stack

        for(int j = 0; j < sectors; ++j, ++k1, ++k2)
        {
            // 2 triangles per sector excluding first and last stacks
            // k1 => k2 => k1+1
            if(i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if(i != (stacks-1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }

}

Ball::show(SceneOpenGL scene) {

}

Ball::~Ball() {}

