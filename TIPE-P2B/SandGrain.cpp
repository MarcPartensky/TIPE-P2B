//
//  SandGrain.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 16/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

// #include "main.cpp"
#include "SandGrain.hpp"
#include "glm/gtc/matrix_access.hpp"

// glm::mat<

SandGrain::SandGrain(const glm::mat3 tensor, float radius, float mass) {
   this->tensor = tensor;
   this->radius = radius;
   this->mass = mass;
}
SandGrain::~SandGrain() {}

glm::vec3 SandGrain::getPosition() {
   return glm::column(&this->tensor,0);
}

glm::vec3 SandGrain::getVelocity() {
   return this->tensor[1];
}

glm::vec3 SandGrain::getAcceleration() {
    return this->tensor[2];
}

void SandGrain::update(float dt) {
   this->tensor[0] += this->tensor[1] * dt;
   return;
}

glm::mat3 SandGrain::getUpdateMatrix(float dt) {
   glm::mat3 matrix = {
       1, dt, dt*dt,
       0, 1, dt,
       0, 0, 0
   };
   return matrix*this->tensor;
}
