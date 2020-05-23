//
//  SandBox.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 17/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

// The board is a material cobble that can interact with the sand

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>

#include "glm/glm.hpp"

struct Board {
    Board(void);
    ~Board();
    void show(void);
    void collideWithSand(SandBox &sandBox);
    glm::fmat3 getBase(float angle);
    glm::fvec3 position;
    glm::fvec3 rotation;
    float color[3];
    int size;
    float scale[3];
    int angle;
    float damping;
};

#endif /* Board_hpp */
