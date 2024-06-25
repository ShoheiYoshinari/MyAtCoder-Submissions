#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
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
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<ll>> dp(h+1, vector<ll> (w+1, 0));
    set<pair<ll, ll>> e;
    rep(i, n){
        int x, y; cin >> x >> y;
        e.insert({x, y});
    }

    dp[1][1] = 1;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if (e.find({i, j}) != e.end()) {
                dp[i][j] = 0;
            } else {
                if (i > 1) dp[i][j] += dp[i-1][j];
                if (j > 1) dp[i][j] += dp[i][j-1];
            }
        }
    }
    // rep(i, 1, h+1){
    //     rep(j, 1, w+1){
    //         cout << dp[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    cout << dp[h][w] << endl;
    return 0;
}