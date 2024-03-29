#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int h ,w;
    cin >> h >> w;
    char a[h+1][w+1];
    rep(i, h){
        rep(j, w) cin >> a[i][j];
    }

    int yoko = 0, tate = 0, ansmaxx = 1009, ansmaxy = 1009, ansx, ansy;
    rep(i, h){
        yoko = 0;
        rep(j, w){
            if(a[i][j] == '#') yoko++;
        }
        if(ansmaxx > yoko && yoko != 0){
            ansmaxx = yoko;
            ansx = i;
        }
    }
    rep(i, w){
        tate = 0;
        rep(j, h){
            if(a[j][i] == '#') tate++;
        }
        if(ansmaxy > tate && tate != 0){
            ansmaxy = tate;
            ansy = i;
        }
    }

    cout << ansx << ' ' << ansy << endl;
}