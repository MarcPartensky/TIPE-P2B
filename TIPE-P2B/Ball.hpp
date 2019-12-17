//
//  Ball.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 15/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <vector>
#include <glm/glm.hpp>



class Ball {
public:
    Ball(glm::vec3 position, float radius);
    ~Ball();

protected:
    glm::vec3 position;
    float radius;
};

#endif /* Ball_hpp */
