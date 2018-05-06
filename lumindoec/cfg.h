//
//  cfg.h
//  lumindoec
//
//  Created by 以明 on 2018/5/6.
//  Copyright © 2018年 以明. All rights reserved.
//
#ifndef cfg_h
#define cfg_h

#include "production.h"

using namespace std;

class CFG {
    public:
        CFG(vector<char> v, vector<char> t, vector<Production> p, char s) : V(v), T(t), P(p), S(s) {}
        void membership_test();
        void show();
    private:
        vector<char> V; // the set of variables
        vector<char> T; // the set of terminals
        vector<Production> P; // the set of productions
        char S; // the start symbol
};

#endif /* cfg_h */
