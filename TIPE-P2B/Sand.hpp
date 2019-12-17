//
//  Sand.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 16/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#ifndef Sand_hpp
#define Sand_hpp

#include <stdio.h>
#include <glm/glm.hpp>

class Sand {
public:
    Sand(glm::mat3 matrix);
    ~Sand();
    glm::vec3 getPosition();
    glm::vec3 getVelocity();
    glm::vec3 getAcceleration();
    void update(float dt);
protected:
    glm::mat3 matrix;
};

#endif /* Sand_hpp */
