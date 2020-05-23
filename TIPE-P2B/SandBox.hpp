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

// #include "Sand.hpp"
#include <stdio.h>

#include "glm/glm.hpp"

// typedef glm::mat<n*3, 3, float, glm::defaultp> mat3nx3;

struct SandBox {
    SandBox();
    // SandBox(glm::mat3 matrices[], float colors[]);
    ~SandBox();
    void init(void);
    void updateUpdateMatrix(void);
    void fillZeroPush(void);
    void fillRandomColors(void);
    void fillMatrices(void);
    void show(void);
    void printMatrix(glm::fmat3 matrix);
    void printVector(glm::fvec3 vector);
    void limitCube(void);
    void limitVelocity(glm::fvec3 velocity);
    void update(void);
    void updatePush(void);
    void updateMatrices(void);
    void resetAccelerations(void);
    void applyGravity(void);
    void applyCollisions(void);
    void applyWindNoise(void);

    float colors[n];
    glm::fmat3 matrices[n];
    glm::fmat3 updateMatrix;
    glm::fvec3 push[n];
    float dt; // infinitesimal duration
    float g; // gravity
    float m; // mass
    float ad; // acceleration damping
    float vd; // velocity damping
    float pd; // position damping
    float vl; // velocity limit
    float sand_friction;
    float initial_position_noise;
    float wind_noise;
    int cube_size; // size of the limit cube
    float cube_bouncing; // bouncing factor of the cube
    float cube_friction;
    int radius; // sand radius
    int stacks; // sand stacks
    int sectors; // sand sectors
    int zone; // zone
    int turns; // number of calls of the update method
};

#endif /* SandBox_hpp */
