#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0,ans = -1;
    int cnt_t = 0;
    bool t = false;
    rep(i, n){
        if(s[i] == 'o') {
            cnt++;
        }else if(s[i] == '-'){
            if(cnt != 0){
                ans = max(ans,cnt);
                cnt = 0;
                t = false;
            }
            if(i == 0){
                t = true;
            }
        }
    }
    if(t){
        if(cnt != 0) ans = cnt;
    }
    cout << ans << endl;
}