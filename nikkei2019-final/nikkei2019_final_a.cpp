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

ll n;
int main(){
    cin >> n;
    vector<ll> a(n+1);
    rep2(i, 1, n) cin >> a[i];

    ll s[n+1];
    s[0] = 0;
    rep2(i, 1, n){
        s[i] = s[i-1] + a[i];
    }

    rep2(i, 1, n){
        ll ans = -1;
        rep2(j, i, n){
            ans = max(ans, s[j] - s[j-i]);
        }
        cout << ans << endl;
    }
    return 0;
}