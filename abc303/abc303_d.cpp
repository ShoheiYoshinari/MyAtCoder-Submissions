#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
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
    ll x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;

    vector<vector<ll>> dp(s.size()+1, vector<ll>(2, HINF<ll>()));
    dp[0][0] = 0;

    rep(i, s.size()){
        if(s[i] == 'a'){
            chmin(dp[i+1][0], dp[i][0] + x);
            chmin(dp[i+1][0], dp[i][1] + z + x);
            chmin(dp[i+1][1], dp[i][0] + z + y);
            chmin(dp[i+1][1], dp[i][1] + y);
        }else{
            chmin(dp[i+1][0], dp[i][0] + y);
            chmin(dp[i+1][0], dp[i][1] + z + y);
            chmin(dp[i+1][1], dp[i][0] + z + x);
            chmin(dp[i+1][1], dp[i][1] + x);
        }
    }
    cout << min(dp[s.size()][0], dp[s.size()][1]) << endl;
}