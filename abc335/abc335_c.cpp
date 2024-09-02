#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) < (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) < (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
#define INF (long long)1e+18
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
}INIT;
int main(){
    int n, q;
    cin >> n >> q;
    deque<pair<ll, ll>> d;

    rep(i, n){
        d.push_back({i+1, 0});
    }

    rep(i, q){
        ll a; cin >> a;
        if(a == 1){
            char c; cin >> c;
            auto [nx, ny] = d[0];
            if(c == 'R') d.push_front({nx+1, ny});
            if(c == 'L') d.push_front({nx-1, ny});
            if(c == 'U') d.push_front({nx, ny+1});
            if(c == 'D') d.push_front({nx, ny-1});
            d.pop_back();
        }else if(a == 2){
            ll x; cin >> x;
            x--;
            cout << d[x].first << ' ' << d[x].second << endl;
        }
    }
}