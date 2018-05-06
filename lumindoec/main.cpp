//
//  main.cpp
//  lumindoec
//
//  Created by 以明 on 2018/5/6.
//  Copyright © 2018年 以明. All rights reserved.
//

#include "cfg.h"

int main(void) {
    int n_v, n_t, n_p;
    vector<char> v_list, t_list;
    vector<Production> p_list;
    char s;
    cout << "Type in the number of variables: " << endl;
    cin >> n_v;
    for (int i = 0; i < n_v; ++i) {
        cout << "Type in the variables: " << endl;
        char v;
        cin >> v;
        v_list.push_back(v);
    }
    cout << "Type in the number of terminals: " << endl;
    cin >> n_t;
    for (int i = 0; i < n_t; ++i) {
        cout << "Type in the terminals: " << endl;
        char t;
        cin >> t;
        t_list.push_back(t);
    }
    cout << "Type in the number of productions: " << endl;
    cin >> n_p;
    for (int i = 0; i < n_p; ++i) {
        cout << "Type in the head of the production: " << endl;
        char h;
        cin >> h;
        cin.get();
        cout << "Type in the body of the production: " << endl;
        string b;
        getline(cin, b);
        Production p(h, b);
        p_list.push_back(p);
    }
    cout << "Type in the start symbol";
    cin >> s;
    CFG cfg(v_list, t_list, p_list, s);
    cfg.show();
    cfg.membership_test();
    
    return 0;
}
