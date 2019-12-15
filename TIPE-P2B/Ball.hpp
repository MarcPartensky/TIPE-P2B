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
    Ball(std::vector<double> position, double radius);
    ~Ball();
protected:
    std::vector<double> mPosition;
    double mRadius;
};

#endif /* Ball_hpp */
