//
//  SandBox.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 17/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

// This contains the state of all grain of sands in an array of matrices

#ifndef SandBox_hpp
#define SandBox_hpp

#include <stdio.h>

#include "glm/glm.hpp"

struct SandBox {
    SandBox();
    ~SandBox();
    void init(void);
    void fillZeroPush(void);
    void fillRandomColors(void);
    void fillMatrices(void);
    void show(void);
    void update(void);
    void updateUpdateMatrix(void);
    void updateMatrices(void);
    void printMatrix(glm::fmat3 matrix);
    void printVector(glm::fvec3 vector);
    void limitCube(void);
    void updatePush(void);
    void resetAccelerations(void);
    void applyGravity(void);
    void applyCollisions(void);
    void applyWindNoise(void);

    float colors[n];
    glm::fmat3 matrices[n];
    glm::fmat3 updateMatrix;
    glm::fvec3 push[n];
    float dt; // infinitesimal duration
    float g; // constant of gravity
    float m; // mass
    float ad; // acceleration damping
    float vd; // velocity damping
    float pd; // position damping
    float sand_friction;
    float initial_position_noise;
    float wind_noise;
    int cube_size; // size of the limit cube
    float cube_bouncing; // bouncing factor of the cube
    float cube_friction; // friction factor of the cube
    int radius; // sand radius
    int stacks; // sand stacks
    int sectors; // sand sectors
    int zone; // spawn zone
    int turns; // number of calls of the update method
};

#endif /* SandBox_hpp */
