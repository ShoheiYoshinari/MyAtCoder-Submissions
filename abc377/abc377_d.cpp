#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

int main() {
  ll n, m;
  cin >> n >> m;
  
  vector<pair<ll, ll>> lr(n);
  rep(i, n) cin >> lr[i].first >> lr[i].second;
  
  vector<ll> mp(m+2, 1e18);
  mp[m+1] = m+1;
  rep(i, n) mp[lr[i].first] = min(mp[lr[i].first], lr[i].second);
  
  for(int i = m; i >= 1; i--){
    chmin(mp[i], mp[i+1]);
  }
  
  ll ans = 0;
  for(int i = 1; i <= m; i++){
    ans += mp[i]-i;
    //cout << mp[i] << ' ' << i << endl;
  }
  cout << ans << endl;
  return 0;
}
