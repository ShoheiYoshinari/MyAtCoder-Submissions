#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i <= (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)

ll n, p, q, r;
ll a[200009];
set<ll> s;
ll tmp = 0;

int main(){
    cin >> n >> p >> q >> r;
    rep2(i, 1, n) cin >> a[i];

    s.insert(0);
    rep2(i, 1, n){
        tmp += a[i];
        s.insert(tmp);
    }

    for(auto x : s){
        if(s.find(x+p) != s.end() && s.find(x+p+q) != s.end() && s.find(x+p+q+r) != s.end()){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
