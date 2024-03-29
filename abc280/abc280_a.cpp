#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int h,w;
    cin >> h >> w;
    string s;
    int ans = 0;
    
    rep(i, h){
        cin >> s;
        rep(j, w) {
            if(s[j] == '#') ans++;
        }
    }
    cout << ans << endl;
}