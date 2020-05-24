//
//  SandBox.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 17/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#include "SandBox.hpp"
// #include <stdio.h>


// SandBox::SandBox(glm::mat3 &matrices[], float &colors[]) :
//         matrices(matrices),
//         colors(colors)
// {
//     init();
// }

SandBox::SandBox() {
    init();
}

void SandBox::init() {
    dt = 0.02;
    g = 100;
    m = 10;
    pd = 0.3;
    vd = 0.8;
    ad = 0.9;
    sand_friction = 0.1;
    cube_size = 100;
    cube_bouncing = 0.05;
    cube_friction = 0.1;
    radius = 2;
    stacks = 20;
    sectors = 20;
    zone = 10;
    turns = 0;
    wind_noise = 0.00;
    initial_position_noise = 0.1;
    fillZeroPush();
    fillRandomColors();
    fillMatrices();
    updateUpdateMatrix();
    update();
}

SandBox::~SandBox() {}

void SandBox::updateUpdateMatrix(void) {
    updateMatrix[0][0] = updateMatrix[1][1] = updateMatrix[2][2] = 1.f;
    updateMatrix[0][1] = updateMatrix[1][2] = dt;
    updateMatrix[0][2] = dt*dt;
    updateMatrix[1][0] = 0.0f;
    updateMatrix[2][0] = updateMatrix[2][1] = 0.0f;
}

void SandBox::update(void) {
    resetAccelerations();
    applyGravity();
    fillZeroPush();
    applyCollisions();
    updatePush();
    applyWindNoise();
    updateMatrices();
    limitCube();
    turns += 1;
}

void SandBox::resetAccelerations(void) {
    for(auto & matrix : matrices) {
        matrix[2][0] = matrix[2][1] = matrix[2][2] = 0.0f;
    }
}

void SandBox::applyGravity(void) {
    for(auto & matrix : matrices) {
        matrix[2][1] -= g;
    }
}

void SandBox::applyCollisions(void) {
    float fv = sand_friction;
    glm::fvec3 p1, p2, v, nv;
    float dist;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            p1 = matrices[i][0];
            p2 = matrices[j][0];
            dist = glm::distance(p1, p2);
            if (dist<2*radius) {
                v = p2-p1;
                nv = glm::normalize(v);
                v = nv;
                push[i] -= (2*radius-dist)/2*nv;
                push[j] += (2*radius-dist)/2*nv;
                matrices[i][2] -= 2*m/dt*(1-ad)*v;
                matrices[j][2] += 2*m/dt*(1-ad)*v;
                matrices[i][1] *= (1-fv);
                matrices[j][1] *= (1-fv);
            }
        }
    }
}

void SandBox::applyWindNoise(void) {
    for (auto & matrix : matrices) {
        for (int j=0; j<3; j++) {
            matrix[1][j] += wind_noise*(float(rand()%10)/5-1);
        }
    }
}

void SandBox::updateMatrices(void) {
    for(auto & matrix : matrices) {
        matrix = matrix * updateMatrix;
    }
}

void SandBox::updatePush(void) {
    for(int i=0; i<n; i++) {
        if (glm::length(push[i])>0) {
            matrices[i][0] += (1-pd)*push[i];
            matrices[i][1] += (1-vd)*push[i]/dt;
        }
    }
}

void SandBox::printMatrix(glm::fmat3 matrix) {
    for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
            std::cout << matrix[y][x] << ",";
        }
        std::cout << std::endl;
    }
}

void SandBox::printVector(glm::fvec3 vector) {
    for (int x=0; x<3; x++) {
        std::cout << vector[x] << ",";
    }
    std::cout << std::endl;
}

void SandBox::show(void) {
    glColor3f(0, 0, 0);
    glutWireCube(cube_size);

    for (int i=0; i<n; i++) {
        glColor3f(
            colors[i],
            colors[i],
            0
        );
        glPushMatrix();
        glTranslatef(
            matrices[i][0][0],
            matrices[i][0][1], 
            matrices[i][0][2]
        );
        glutSolidSphere(radius, stacks, sectors);
        glPopMatrix();
    }
}

void SandBox::fillZeroPush(void) {
    for (auto & p : push) {
        p = glm::fvec3(0, 0, 0);
    }
}

void SandBox::fillRandomColors(void) {
    for (auto & color : colors) {
        color = (float(rand())/RAND_MAX+1)/2;
    }
}

// void SandBox::fillMatrices(void) {
//     for (int i=0; i<n; i++) {
//         for (int j=0; j<3; j++) {
//             matrices[i][0][j] = float(rand()%(2*zone)-zone);
//             matrices[i][1][j] = 0.0f;
//             matrices[i][2][j] = 0.0f;
//         }
//     }
// }

void SandBox::fillMatrices(void) {
    float f = initial_position_noise;
    float x, y, z;
    for (int i=0; i<n; i++) {
        x = 3*(i%10)+f*float(rand()%10)/10;
        y = 3*((i/100)%10)+f*float(rand()%10)/10;
        z = 3*((i/1000)%10)+f*float(rand()%10)/10;
        // std::cout << x << "," << y << "," << z << std::endl;
        matrices[i][0][0] = x;
        matrices[i][0][1] = y;
        matrices[i][0][2] = z;
        for (int j=0; j<3; j++) {
            matrices[i][1][j] = 0.0f;
            matrices[i][2][j] = 0.0f;
        }
    }
}

void SandBox::limitCube(void) {
    for (auto & matrix : matrices) {
        for (int j=0; j<3; j++) {
            if (matrix[0][j] < -cube_size/2+radius) {
                matrix[0][j] = -cube_size/2+radius;
                matrix[1][j] *= -cube_bouncing;
                matrix[1] *= (1-cube_friction);
            }
            if (matrix[0][j] > cube_size/2-radius) {
                matrix[0][j] = cube_size/2-radius;
                matrix[1][j] *= -cube_bouncing;
                matrix[1] *= (1-cube_friction);
            }
        }
    }
}