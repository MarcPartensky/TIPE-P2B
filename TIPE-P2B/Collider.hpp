//
//  Collider.hpp
//  TIPE-P2B
//
//  Created by Marc Partensky on 16/12/2019.
//  Copyright © 2019 Marc Partensky. All rights reserved.
//

#ifndef Collider_hpp
#define Collider_hpp

#include <stdio.h>
#include "SandBox.hpp"

class Collider {
/* The collider is charged of dealing with the collisions of the sand in the sand box.*/
public:
//    Collider(SandBox sandbox);
    Collider();
    ~Collider();
    void update();
protected:
//    SandBox sandbox;
};

#endif /* Collider_hpp */
