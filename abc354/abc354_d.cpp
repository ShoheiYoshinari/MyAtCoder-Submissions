#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

ll f(ll a, ll b){
    // ra, rbでx, yの余りを求めて周期的な形の個数を求める
    ll ra = a%4; a -= ra;
    ll rb = b%2; b -= rb;
    ll res = a*b;
    if(rb) res += a;
    if(ra >= 1){
        res += b*3/2;
        if(rb) res += 2;
    }
    if(ra >= 2){
        res += b*3/2;
        if(rb) res += 1;
    }
    if(ra >= 3) res += b/2;
    return res;
}

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a += 1e9;
    b += 1e9;
    c += 1e9;
    d += 1e9;

    ll ans = f(c, d) - f(a, d) - f(c, b) + f(a, b);
    cout << ans << endl;
    return 0;
}