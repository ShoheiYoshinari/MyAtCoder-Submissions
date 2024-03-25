#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int n;
ll a, b;
string s;

int main(){
    cin >> n >> a >> b >> s;

    ll ans = 1ll << 60;
    ll tmp = 0;
    rep(i, n){
        tmp = a*i;
        rep(j, n/2){
            int l = (i+j)%n;
            int r = (i+n-1-j)%n;
            if(s[l] != s[r]) tmp += b;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
