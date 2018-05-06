//
//  production.h
//  lumindoec
//
//  Created by 以明 on 2018/5/6.
//  Copyright © 2018年 以明. All rights reserved.
//

#ifndef production_h
#define production_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Production {
    public:
        Production(char h, string b) : head(h), body(b) {}
        char head;
        string body;
};

#endif /* production_h */
