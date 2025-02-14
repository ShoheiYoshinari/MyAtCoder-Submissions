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
    int n, x;
    cin >> n >> x;
    vector<vector<pair<int, int>>> food(3);
    rep(i, n){
        int v, a, c;
        cin >> v >> a >> c;
        v--;
        food[v].push_back({a, c});
    }

    vector<vector<int>> d(3, vector<int>(x+1));
    rep(v, 3){
        vector<int> dp(x+1);
        for(auto[a, c] : food[v]){
            for(int i = x; i >= c; i--){
                chmax(dp[i], dp[i-c]+a);
            }
        }
        d[v] = dp;
    }
    
    
    auto judge = [&](int r){
        int tot = 0;
        rep(v, 3){
            if(d[v][x] < r) return false;
            int need = lower_bound(all(d[v]), r) - d[v].begin();
            tot += need;
        }
        return tot <= x;
    };

    ll ok = 0, ng = 1001001001;
    while(ok+1 < ng){
        ll mid = (ok+ng)/2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}