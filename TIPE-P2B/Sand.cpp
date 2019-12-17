//
//  Sand.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 16/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#include "Sand.hpp"

Sand::Sand(glm::mat3 matrix) {
    Sand::matrix = matrix;
}

Sand::~Sand() {}

glm::vec3 Sand::getPosition() {
    return matrix[0];
}

glm::vec3 Sand::getVelocity() {
    return matrix[1];
}

glm::vec3 Sand::getAcceleration() {
    return matrix[2];
}

void Sand::update(float dt) {
    matrix[1] += matrix[2] * dt;
    matrix[0] += matrix[1] * dt;
    return;
}
