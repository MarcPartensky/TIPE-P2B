//
//  SandGrain.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 16/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#include "main.cpp"
#include "SandGrain.hpp"

SandGrain::SandGrain(glm::mat3 tensor, float radius, float mass) {
    SandGrain::tensor = tensor;
    SandGrain::radius = radius;
    SandGrain::mass = mass;
}

SandGrain::~SandGrain() {}

glm::vec3 SandGrain::getPosition() {
    return tensor[0];
}

glm::vec3 SandGrain::getVelocity() {
    return tensor[1];
}

glm::vec3 SandGrain::getAcceleration() {
    return tensor[2];
}

void SandGrain::update(float dt) {
    tensor[1] += tensor[2] * dt;
    tensor[0] += tensor[1] * dt;
    return;
}

glm::mat3 SandGrain::getUpdateMatrix(float dt) {
    glm::mat3 matrix = {
        1, dt, dt*dt,
        0, 1, dt,
        0, 0, 0
    };
    return matrix*tensor;
}
