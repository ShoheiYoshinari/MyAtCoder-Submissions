#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
    int n, q, s, t;
    cin >> n >> q;
    vector<vector<int>> a(n);
    rep(i, n){
        int l;
        cin >> l;
        a[i].resize(l);
        rep(j, l){
            cin >> a[i][j];
        }
    }
    rep(i, q){
        cin >> s >> t;
        cout << a[s-1][t-1] << endl;
    }
}
