//
//  SandGrain.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 16/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>

struct Camera {
public:
    Camera();
    Camera(glm::vec3 eye, glm::vec3 center, glm::vec3 up);
    void look(void);
    ~Camera();
    glm::vec3 eye;
    glm::vec3 center;
    glm::vec3 up;
};

#endif /* Camera_hpp */

