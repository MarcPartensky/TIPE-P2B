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
#include "Sand.hpp"


class SandBox {
public:
    SandBox(Sand array[]);
    ~SandBox();
protected:
    Sand array[];
//    std::vector<Sand> array;
};

#endif /* SandBox_hpp */
