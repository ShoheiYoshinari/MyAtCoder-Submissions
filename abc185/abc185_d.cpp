#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m+2, 0);
    rep(i, m) cin >> a[i];
    a[m] = 0;
    a[m+1] = n+1;

    sort(all(a));

    if(n == m){
        cout << 0 << endl;
        return 0;
    }
    if(m == 0){
        cout << 1 << endl;
        return 0;
    }

    ll min = n;
    vector<ll> v;
    rep2(i, 0, m){
        if(a[i+1]-a[i]-1 == 0) continue;
        chmin(min, a[i+1]-a[i]-1);
        v.push_back(a[i+1]-a[i]-1);
    }

    ll ans = 0;
    for(auto len : v) ans += (len+min-1)/min;
    cout << ans << endl;
    return 0;
}