#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ass(m);

    rep(i, m){
        int c;
        cin >> c;
        
        ass[i].resize(c);
        for(int j = 0; j < ass[i].size(); j++) cin >> ass[i][j];
    }

    int ans = 0;

    for (int bit = 0; bit < (1<<m); bit++){
        set<int> S;
        for(int i = 0; i < m; i++){
            if((bit>>i) & 1) {
                for(int j = 0; j < ass[i].size(); j++) {
                    S.insert(ass[i][j]);
                }
            }
        }
        if(S.size() == n) ans++;
    }
    cout << ans << endl;
}