//
//  Sand.cpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 05/04/2020.
//  Copyright © 2020 Marc Partensky. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera() {
    this->eye = glm::vec3(0, 0, 0);
    this->center = glm::vec3(0, 0, 1);
    this->up = glm::vec3(0, 1, 0);
}

Camera::Camera(
        glm::vec3 eye,
        glm::vec3 center,
        glm::vec3 up
    ) :
    eye(eye),
    center(center),
    up(up)
{
    this->eye = eye;
    this->center = center;
    this->up = up;
}

void Camera::look(void) {
    gluLookAt(
        this->eye.x, this->eye.y, this->eye.z, 
        this->center.x, this->center.y, this->center.z,
        this->up.x, this->up.y, this->up.z
    );
}

Camera::~Camera() {}

