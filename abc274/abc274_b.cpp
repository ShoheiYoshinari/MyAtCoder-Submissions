#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int h, w;
    cin >> h >> w;
    char c[h][w];
    rep(i, h){
        rep(j, w) cin >> c[i][j];
    }

    rep(j, w){
        int ans = 0;
        rep(i, h){
            if(c[i][j] == '#') ans++;
        }
        cout << ans << endl;
    }


}                               