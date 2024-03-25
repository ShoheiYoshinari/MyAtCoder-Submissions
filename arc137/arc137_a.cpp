#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i <= (ll)(n); i++)

ll l, r;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
int main(){
    cin >> l >> r;
    ll ans = r - l;

    while(true){
        rep2(i, l, r-ans){
            if(gcd(i, i+ans) == 1){
                cout << ans << endl;
                return 0;
            }
        }
        ans--;
    }
}