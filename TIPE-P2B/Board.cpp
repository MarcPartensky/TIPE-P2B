//
//  Board.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 17/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#include "Board.hpp"


Board::Board(void) {
    position = glm::fvec3(0, 0, 0);
    rotation = glm::fvec3(0, 0, 1);
    color[0] = 153./256;
    color[1] = 102./256;
    color[2] = 0./256;
    scale[0] = 0.05;
    scale[1] = 2;
    scale[2] = 1;
    angle = 70;
    size = 100;
    damping = 0.7;

}

Board::~Board() {}

glm::fmat3 Board::getBase(float angle) {
    return glm::fmat3(
        std::cos(angle), -std::sin(angle), 0,
        std::sin(angle),  std::cos(angle), 0,
                      0,                0, 1
    );
}

void Board::collideWithSand(SandBox &sandBox) {
    const double pi = std::acos(-1);
    glm::fmat3 base = getBase(-float(angle)*pi/180);
    glm::fmat3 inv_base = getBase(float(angle)*pi/180);

    glm::fvec3 normal = base * glm::fvec3(1, 0, 0);
    glm::fvec3 p, v;
    glm::fmat3 mat;

    float x, y, z;
    float h;
    float hb = scale[0]*size;
    float margin = sandBox.radius+hb/2;

    for (int i=0; i<n; i++) {
        p = glm::dot(normal,sandBox.matrices[i][0]) * normal;
        h = glm::length(p);
        if (h<margin && h>-margin) {
            if (showCout) {
                std::cout << "height:" << h << std::endl;
            }
            sandBox.matrices[i][0] -= (h-hb/2-sandBox.radius)*normal;
            sandBox.matrices[i][1] *= (1-damping);
            // v = base * sandBox.matrices[i][1];
            // v[1] *= -1;
            // sandBox.matrices[i][1] = inv_base * v;
            // sandBox.matrices[i][1][0] = 0;
            // sandBox.matrices[i][1][1] = 0;
            // sandBox.matrices[i][1][2] = 0;
        }
    }

}

void Board::show(void) {
    glColor3f(
        color[0],
        color[1],
        color[2]
    );
    glPushMatrix();
    glTranslatef(
        position.x,
        position.y,
        position.z
    );
    glRotatef(
        angle,
        rotation.x,
        rotation.y,
        rotation.z
    );
    glScalef(
        scale[0],
        scale[1],
        scale[2]
    );
    glutSolidCube(size);
    glPopMatrix();
}