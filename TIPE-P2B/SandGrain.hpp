//
//  SandGrain.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 16/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#ifndef SandGrain_hpp
#define SandGrain_hpp

#include <stdio.h>

class SandGrain {
public:
    static SandGrain createRandom();
    SandGrain(glm::mat3 tensor, float radius, float mass);
    ~SandGrain();
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

#endif /* SandGrain_hpp */

