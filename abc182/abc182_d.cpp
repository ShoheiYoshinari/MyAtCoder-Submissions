#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


ll n;
ll a[200009];


int main(){
    cin >> n;
    rep(i, n) cin >> a[i];

    ll ans = 0;
    ll s = 0, b = 0;
    ll max_b = 0;

    rep(i, n){
        b += a[i];
        max_b = max(max_b, b);
        ans = max(ans, s + max_b);
        s += b; 
    }
    cout << ans << endl;
    return 0;
}

