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
    int n;
    cin >> n;
    vector<vector<vector<ll>>> a(n, vector<vector<ll>>(n, vector<ll>(n, 0ll)));
    rep(i, n){
        rep(j, n){
            rep(k, n){
                cin >> a[i][j][k];
            }
        }
    }

    vector s(n+1, vector(n+1, vector(n+1, 0ll)));
    rep(i, n){
        rep(j, n){
            rep(k, n){
                s[i+1][j+1][k+1] = s[i][j+1][k+1] + s[i+1][j][k+1] + s[i+1][j+1][k]
                - s[i][j][k+1] - s[i][j+1][k] - s[i+1][j][k] + s[i][j][k] + a[i][j][k];
            }
        }
    }

    int q;
    cin >> q;
    rep(i, q){
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--, ly--, lz--;
        cout << s[rx][ry][rz] - s[lx][ry][rz] - s[rx][ly][rz] - s[rx][ry][lz]
        + s[lx][ly][rz] + s[lx][ry][lz] + s[rx][ly][lz] - s[lx][ly][lz] << endl;
    }
    return 0;
}