#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    
    int ans = 0;
    rep(i, n){
        for(int j = i+1; j < n; j++){
            bool can = true;
            rep(k, m){
                if(s[i][k] == 'x' && s[j][k] == 'x') can = false;    
            }
            if(can) ans++;
        }
    }
    cout << ans << endl;
}