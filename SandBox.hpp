//
//  SandBox.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 17/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#ifndef SandBox_hpp
#define SandBox_hpp

#include <stdio.h>
#include <glm/glm.hpp>

const int n = 1000;

class SandBox {
public:
    SandBox();
    ~SandBox();
protected:
    const int n;
    glm::mat<3, 3, float> tensor;
    
};

#endif /* SandBox_hpp */
