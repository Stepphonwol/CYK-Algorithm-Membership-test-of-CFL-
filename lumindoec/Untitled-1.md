### CYK Algorithm(Membership test of CFL)
#### program structure
- designing a class for the productions
```
class Production {
    public:
        Production(char h, string b) : head(h), body(b) {}
        char head;
        string body;
};
```
- designing a class for a CFG
```
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
```
#### basis step for CYK
```
    for (int i = 0; i < len; ++i) {
        char test = w[i];
        for (auto p : P) {
            if (p.body.size() == 1 && p.body[0] == test) {
                table[i][i].push_back(p.head);
            }
        }
    }
```
#### induction step for CYK
```
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
```
#### final step for CYK
```
    if (table[0][len - 1].find(S) != string::npos) {
        cout << w << " is in this CFG" << endl;
    }
    else {
        cout << w << " is not in this CFG" << endl;
    }
```
#### results
- The test was based on the following CFG:
![](1.PNG)
- The input string is *baaba*
- The results are as followed. The rest output describes the content of the CYK table.
![](2.PNG)