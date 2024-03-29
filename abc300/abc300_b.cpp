#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int h, w;
    cin >> h >> w;
    char a[h][w], b[h][w];
    rep(i, h){
        rep(j, w) cin >> a[i][j];
    }
    rep(i, h){
        rep(j, w) cin >> b[i][j];
    }

    rep(i, h){
        rep(j, w){
            bool ans = true;
            rep(s, h){
                rep(t, w){
                    if(a[(i+s) % h][(j+t) % w] != b[s][t]) ans = false;
                }
            }
            if(ans){
                cout << "Yes" << endl;
                return 0;
            }

        }
    }
    cout << "No" << endl;
}