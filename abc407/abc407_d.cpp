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

int h, w;
ll ans = 0;
void dfs(vector<vector<ll>> &a, vector<vector<bool>> &d, int i, int j) {
    if(j == w){
        j = 0;
        i++;
    }
    if(i == h){
        ll tmp = 0;
        rep(k, h) rep(l, w){
            if(!d[k][l]) tmp ^= a[k][l];
        }
        chmax(ans, tmp);
        return ;
    }
    if(j+2 <= w && !d[i][j] && !d[i][j+1]){
        d[i][j] = true;
        d[i][j+1] = true;
        dfs(a, d, i, j+2);
        d[i][j] = false;
        d[i][j+1] = false;
    }
    if(i+2 <= h && !d[i][j] && !d[i+1][j]){
        d[i][j] = true;
        d[i+1][j] = true;
        dfs(a, d, i, j+1);
        d[i][j] = false;
        d[i+1][j] = false;
    }
    dfs(a, d, i, j+1);
}

int main(){
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w, 0));
    rep(i, h) rep(j, w) cin >> a[i][j];

    vector<vector<bool>> d(h, vector<bool>(w, false));
    dfs(a, d, 0, 0);
    cout << ans << endl;
    return 0;
}