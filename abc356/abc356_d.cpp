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

const ll mod = 998244353;

int main(){
    ll n, m;
    cin >> n >> m;

    ll ans = 0;

    rep2(i, 0, 60){
        ll p2 = 1ll<<i;
        if((m/p2)%2 == 1){
            ans += (n / (2*p2)) * p2;
            ans %= mod;
            ll l = n % (2*p2);
            if(l >= p2){
                ans += (l-p2+1);
                ans %= mod;
            }
        }
    }
    cout << ans << endl;

}