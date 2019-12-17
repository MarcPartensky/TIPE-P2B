//
//  Sand.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 16/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#include "Sand.hpp"

Sand::Sand(glm::mat3 tensor, float radius, float mass) {
    Sand::tensor = tensor;
    Sand::radius = radius;
    Sand::mass = mass;
}

Sand::~Sand() {}

glm::vec3 Sand::getPosition() {
    return tensor[0];
}

glm::vec3 Sand::getVelocity() {
    return tensor[1];
}

glm::vec3 Sand::getAcceleration() {
    return tensor[2];
}

void Sand::update(float dt) {
    tensor[1] += tensor[2] * dt;
    tensor[0] += tensor[1] * dt;
    return;
}

glm::mat3 Sand::getUpdateMatrix(float dt) {
    glm::mat3 matrix = {
        1, dt, dt*dt,
        0, 1, dt,
        0, 0, 0
    };
    return matrix*tensor;
}
