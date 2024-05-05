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

long long n, t, s;
vector<ll> a, b;

int main(){
    cin >> n;
    rep(i, n){
        cin >> t >> s;
        a.push_back(t);
        b.push_back(s);
    }

    ll sum = 0;
    rep(i, n) sum += a[i];

    ll ans = -1;

    rep(i, n){
        ll sm = 0;
        sm += sum - a[i] + b[i];
        ans = max(ans, sm);
    }
    cout << ans << endl;
    return 0;

}