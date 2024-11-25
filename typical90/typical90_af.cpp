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
    int n, m;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n, 0)), bad(n, vector<int> (n, 0));
    rep(i, n) rep(j, n) cin >> a[i][j];
    cin >> m;
    rep(i, m){
        int x, y; cin >> x >> y;
        x--, y--;
        bad[x][y]++;
        bad[y][x]++;
    }

    vector<int> p(n);
    rep(i, n) p[i] = i;
    ll ans = 1e9;
    bool isvalid;
    ll res;
    do{
        res = 0;
        isvalid = true;
        rep(i, n){
            if(i != n-1) if(bad[p[i]][p[i+1]] != 0) isvalid = false;
            res += a[p[i]][i];
        }
        if(isvalid) chmin(ans, res);
    }while(next_permutation(all(p)));

    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}