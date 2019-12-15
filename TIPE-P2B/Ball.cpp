//
//  Ball.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 15/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#include "Ball.hpp"





Ball::Ball(glm::vec3 position[3], float radius) {
    mPosition[0] = position[0];
    mPosition[1] = position[1];
    mPosition[2] = position[2];
    mRadius = radius;
}

Ball::~Ball() {}

