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
    static Sand createRandom();
    Sand(glm::mat3 tensor, float radius, float mass);
    ~Sand();
    glm::vec3 getPosition(); // Position vector extracted from the tensor
    glm::vec3 getVelocity(); // Velocity vector extracted from the tensor
    glm::vec3 getAcceleration(); // Acceleration vector extracted from the tensor
    void update(float dt); // Update the tensor
    glm::mat3 getUpdateMatrix(float dt);
protected:
    glm::mat3 tensor;
    float radius;
    float mass;
};

#endif /* Sand_hpp */

