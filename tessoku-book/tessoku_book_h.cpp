#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main() {
    int h, w, q;
    cin >> h >> w;
    int x[h+1][w+1], s[h+1][w+1];
    rep(i, h){
        rep(j, w) cin >> x[i][j];
    }
    for(int i = 0; i <= h; i++){
        for(int j = 0; j <= w; j++){
            s[i][j] = 0;
        }
    }
    rep(i, h){
        rep(j, w){
            s[i][j] = s[i][j-1] + x[i][j];
        }
    }
    rep(j, w){
        rep(i, h){
            s[i][j] = s[i-1][j] + s[i][j];
        }
    }

    int a, b, c ,d;
    int ans = 0;
    cin >> q;
    rep(i, q){
        cin >> a >> b >> c >> d;
        ans = s[c][d] - s[c][b-1] - s[a-1][d] + s[a-1][b-1];
        cout << ans << endl;
    }



}