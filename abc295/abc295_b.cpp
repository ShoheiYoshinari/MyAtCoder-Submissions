#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int r,c;
    cin >> r >> c;
    vector<vector<char>> b(r);
    rep(i, r) {
        rep(j, c) {
            char x;
            cin >> x;
            b[i].push_back(x);
        }
    }

    rep(i, r) {
        rep(j, c) {
            if(b[i][j] != '.' && b[i][j] != '#'){
                int power = b[i][j] - '0';
                rep(ni, r) {
                    rep(nj, c) {
                    if(abs(i - ni) + abs(j - nj) <= power && b[ni][nj] == '#') {
                        b[ni][nj] = '.';
                    }
                    }
                }

            }
        }
    }

    
    
    rep(i, r) { 
        rep(j ,c) {
            if(b[i][j] != '.' && b[i][j] != '#') { 
                cout << '.';
            }else{
                cout << b[i][j];
            }
        }
        cout << endl;
    }
}