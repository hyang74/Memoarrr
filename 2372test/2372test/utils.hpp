//
//  utils.h
//  Memoarrr
//
//  Created by Huairuo Yang(7895717) & Yifei Du(7824839) on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717) & Yifei Du(7824839). All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp
#include <vector>
const int rewardList[7] ={1,1,1,2,2,3,4};
static bool endOfGame = false;
static bool expertMode = false;

enum Side{
    top = 0,
    bottom,
    left,
    right
};

enum FaceAnimal{
    crab = 0,
    penguin,
    octopus,
    turtle,
    walrus
};

enum FaceBackground {
    red = 0,
    green,
    purple,
    blue,
    yellow
};

enum Letter{
    A = 0,
    B,
    C,
    D,
    E
};
enum Number{
    one = 0,
    two,
    three,
    four,
    five
};

#endif /* utils_h */
