#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> x(n);
    rep(i, m){
        cin >> a >> b;
        x[b-1].push_back(a);
        x[a-1].push_back(b);
    }
    rep(i, n){
        sort(x[i].begin(), x[i].end());
        cout << x[i].size();
        rep(j, x[i].size()){
            cout << ' ' << x[i][j];
        }
        cout << endl;
    }
}