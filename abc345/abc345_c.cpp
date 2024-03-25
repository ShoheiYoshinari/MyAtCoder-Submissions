#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

string s;
long long cnt[29];
long long ans = 0;

int main(){
    cin >> s;
    rep(i, s.size()) cnt[(int)(s[i]-'a')]++;

    rep(i, 26){
        rep2(j, i+1, 26){
            ans += cnt[i] * cnt[j];
        }
    }

    rep(i, 26){
        if(cnt[i] > 1){
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;

}