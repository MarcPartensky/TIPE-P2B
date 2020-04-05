//
//  Sand.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 05/04/2020.
//  Copyright © 2020 Marc Partensky. All rights reserved.
//

#ifndef Sand_hpp
#define Sand_hpp

#include <stdio.h>
#include "glm/glm.hpp"


struct Sand {
//methods
    Sand(glm::mat3 matrix);
    ~Sand();
    void draw();
//attributes
    glm::mat3 matrix;
};

#endif /* Sand_hpp */
