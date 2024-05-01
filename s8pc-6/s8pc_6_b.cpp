#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

ll n;
vector<ll> a(n), b(n);

int main(){
    cin >> n;
    ll s, t;
    rep(i, n){
        cin >> s >> t;
        a.push_back(s);
        b.push_back(t);
    }

    ll ans = 100000000000000000;

    rep(i, n){
        rep(j, n){
            ll sum = 0;
            ll entry = a[i], exit = b[j];
            rep(k, n){
                sum += abs(entry - a[k]);
                sum += abs(a[k] - b[k]);
                sum += abs(b[k] - exit);
            }
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
    
}