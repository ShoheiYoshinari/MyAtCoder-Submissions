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

int n, x;


int main(){
    cin >> n >> x;
    vector<long double> p(n);
    rep(i, n){
        cin >> p[i];
        p[i] /= 100;
    }

    vector<long double> dp(n+1, 0.0);
    dp[0] = 1.0;
    rep(i, n){
        vector<long double> ndp(n+1, 0.0);
        rep(j, n){
            ndp[j] += (1-p[i])*dp[j];
            ndp[j+1] += p[i]*dp[j];
        }
        swap(dp, ndp);
    }

    //rep(i, n) cout << dp[i] << ' ';
    //cout << endl;

    vector<long double> f(x+1, 0.0);
    for(int i = 1; i <= x; i++){
        f[i] += 1.0;
        for(int j = 1; j <= n; j++){
            f[i] += f[max(i-j, 0)]*dp[j];
        }
        f[i] /= (1 - dp[0]);
    }

    cout << f[x] << endl;
    return 0;
}