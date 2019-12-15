//
//  Ball.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 15/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#include "Ball.hpp"


Ball::Ball(std::vector<double> position, double radius) {
    mPosition = position;
    mRadius = radius;
}

Ball::~Ball() {}

