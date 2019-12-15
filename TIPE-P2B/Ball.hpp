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

class Ball {
public:
    Ball(float position[3], float radius);
    ~Ball();

protected:
    float mPosition[3];
    float mRadius;
};

#endif /* Ball_hpp */
