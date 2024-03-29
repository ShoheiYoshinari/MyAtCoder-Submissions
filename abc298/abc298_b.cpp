#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main() {
    int n;
    cin >> n;
    int a[n+1][n+1], b[n+1][n+1];
    rep(i, n){
        rep(j, n) cin >> a[i][j];
    }
    rep(i, n){
        rep(j, n) cin >> b[i][j];
    }

    rep(k, 4){
        int pre[n+1][n+1];
        rep(i, n){
            rep(j, n){
                pre[i][j] = a[n + 1 - j][i];
            }
        }
        bool ans = true;
        rep(i, n){
            rep(j, n){
                if(pre[i][j] == 1 && b[i][j] == 0) ans = false;
            }
        }
        if(ans) {
            cout  << "Yes" << endl;
            return 0;
        }
        rep(i, n){
            rep(j, n){
                a[i][j] = pre[i][j];
            }
        }
    }
    cout << "No" << endl;
}