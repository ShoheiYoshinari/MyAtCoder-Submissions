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

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m+1, vector<int> (n+1));
    rep(i, 1, m+1) rep(j, 1, n+1) cin >> a[i][j];

    vector<vector<int>> dp(m+1, vector<int> ((1<<n)+1, 1e9));
    dp[0][0] = 0;
    rep(i, 1, m+1){
        rep(j, 1<<n){
            vector<int> frees(n+1, 0);
            rep(k, 1, n+1){
                if(j & 1<<(k-1)) frees[k] = 1;
            }

            int v = 0;
            rep(k, 1, n+1){
                if(frees[k] == 1 || a[i][k] == 1) v += (1<<(k-1));
            }

            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][v] = min(dp[i][v], dp[i-1][j] + 1);
        }
    }

    // rep(i, 1, m+1){
    //     rep(j, 1<<n) if(dp[i][j] == 1e9) cout << "x"; else cout << dp[i][j];
    //     cout << endl;
    // }
    cout << (dp[m][(1<<n)-1] == 1e9 ? -1 : dp[m][(1<<n)-1]) << endl;
    return 0;
}