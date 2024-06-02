#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

const ll mod = 998244353;
const ll inv2 = 499122177;

ll triangular_num(ll x){
    x %= mod;
    ll res = x;
    res *= (x+1); res %= mod;
    res *= inv2; res %= mod;
    return res;
}

int main(){
    ll n;
    cin >> n;
    
    ll res = 0;
    ll p10 = 10;
    rep2(i, 1, 18){
        ll l = p10/10;
        ll r = min(n, p10-1);
        if(l <= r){
            res += triangular_num(r-l+1);
            res %= mod;
        }
        p10 *= 10;
    }
    cout << res << endl;
    return 0;

}