#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int r, c, a[2][2];
    cin >> r >> c;
    rep(i, 2){
        rep(j, 2) cin >> a[i][j];
    }

    cout << a[r-1][c-1] << endl;

}