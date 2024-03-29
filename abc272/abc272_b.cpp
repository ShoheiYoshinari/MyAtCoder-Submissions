#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> ck(n, vector<bool>(n, false));
    rep(i, m){
        int k;
        cin >> k;
        vector<int> x(k);
        for(auto &v : x) cin >> v, v--;
        rep(j, x.size()-1){
            rep2(k, j+1, x.size()){
                ck[x[j]][x[k]] = true;
            }
        }
    }
    bool ans = 1;
    rep(i, n){
        rep2(j, i+1, n){
            ans &= ck[i][j];
        }
    }
    cout << (ans ? "Yes" : "No") << endl;

}