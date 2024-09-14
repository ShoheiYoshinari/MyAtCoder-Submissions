#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
} INIT;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n); 
    rep(i, n) cin >> v[i].first;  
    rep(i, n) cin >> v[i].second; 

    sort(all(v));
    vector<ll> s(n+1);
    rep(i, 1, n+1){
        s[i] = s[i-1] + v[i-1].second;
    }

    ll q;
    cin >> q;
    rep(i, q){
        ll l, r;
        cin >> l >> r;
        auto left = lower_bound(all(v), make_pair(l, 0LL)) - v.begin();
        auto right = upper_bound(all(v), make_pair(r, LLONG_MAX)) - v.begin() - 1;

        if (left > right) {
            cout << 0 << endl;
        } else {
            cout << s[right + 1] - s[left] << endl;
        }
    }
    return 0;
}
