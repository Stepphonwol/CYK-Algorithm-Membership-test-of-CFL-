//
//  cfg.cpp
//  lumindoec
//
//  Created by 以明 on 2018/5/6.
//  Copyright © 2018年 以明. All rights reserved.
//

#include "cfg.h"

void CFG::show()
{
    cout << "V: " << endl;
    for (auto c : V) {
        cout << c;
    }
    cout << endl;
    cout << "T: " << endl;
    for (auto c : T) {
        cout << c;
    }
    cout << endl;
    cout << "P: " << endl;
    for (auto c : P) {
        cout << c.head << "->" << c.body << endl;
    }
    cout << "S：" << endl;
    cout << S << endl;
}

void CFG::membership_test()
{
    string w;
    cout << "Type in the string: " << endl;
    cin.get();
    getline(cin, w);
    auto len = w.size();
    string table[len][len];
    // basis step (for the first row, increment = 0)
    for (int i = 0; i < len; ++i) {
        char test = w[i];
        for (auto p : P) {
            if (p.body.size() == 1 && p.body[0] == test) {
                table[i][i].push_back(p.head);
            }
        }
    }
    // induction step (increment >= 1)
    for (int increment = 1; increment < len; ++increment) {
        for (int basis = 0; basis + increment < len; ++basis) {
            int i = basis;
            int j = basis + increment;
            for (int k = i; k < j; ++k) {
                string test1 = table[i][k];
                string test2 = table[k+1][j];
                for (auto t1 : test1) {
                    for (auto t2 : test2) {
                        string unresolved;
                        unresolved.push_back(t1);
                        unresolved.push_back(t2);
                        for (auto p : P) {
                            if (p.body == unresolved) {
                                table[i][j].push_back(p.head);
                            }
                        }
                    }
                }
            }
        }
    }
    // final step
    if (table[0][len - 1].find(S) != string::npos) {
        cout << w << " is in this CFG" << endl;
    }
    else {
        cout << w << " is not in this CFG" << endl;
    }
    /*for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            cout << table[i][j] << i << " " << j << endl;
        }
    }*/
}
