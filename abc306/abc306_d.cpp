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
}INIT;

int main(){
    ll n; cin >> n;
    vector<ll> x(n+1), y(n+1);
    rep(i, 1, n+1) cin >> x[i] >> y[i];

    vector<vector<ll>> dp(n+1, vector<ll> (2, 0));

    rep(i, 1, n+1){
        if(x[i] == 0){
            dp[i][0] = max({dp[i-1][0], dp[i-1][0]+y[i], dp[i-1][1]+y[i]});
            dp[i][1] = dp[i-1][1];
        }else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+y[i]);
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}