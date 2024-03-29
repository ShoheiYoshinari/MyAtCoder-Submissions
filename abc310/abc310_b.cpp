#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n), c(n);
    int f[n][m];
    rep(i, n){
        cin >> p[i] >> c[i];
        rep(j, c[i]){
            int a;
            cin >> a;
            f[i][j] = a;
        }
    }

    rep(i, n){
        rep(j, n){
            bool ans1 = false, ans2 = false, ans3 = true;
            if(p[i] >= p[j]) ans1 = true;
            if(c[i] < c[j] || p[i] > p[j]) ans2 = true;
            rep(k, c[i]){
                bool ck = false;
                int tmp = f[i][k];
                rep(l, c[j]){
                    if(tmp == f[j][l]) ck = true;
                }
                if(!ck) ans3 = false;
            }

            if(ans1 & ans2 & ans3){
                cout << "Yes" <<endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}