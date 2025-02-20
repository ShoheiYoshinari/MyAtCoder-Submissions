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

int n;

auto rotate(vector<vector<char>> &v){
    vector<vector<char>> res(n, vector<char>(n));
    rep(i, n){
        rep(j, n) res[j][n-i-1] = v[i][j];
    }
    return res;
}

bool match(vector<vector<char>> &s, vector<vector<char>> &t, int i, int j){
    rep(k, n){
        rep(l, n){
            if(s[(i+k)%n][(j+l)%n] != t[k][l]) return  false;
        }
    }
    return true;
}

int main(){
    cin >> n;
    vector<vector<char>> s(n+1, vector<char>(n+1, '.')), t(n+1, vector<char>(n+1, '.'));
    rep(i, n) rep(j, n) cin >> s[i][j];
    rep(i, n) rep(j, n) cin >> t[i][j];
    n++;

    rep(dir, 4){
        rep(i, n){
            rep(j, n){
                if(match(s, t, i, j)){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        s = rotate(s);
    }
    cout << "No" << endl;
    return 0;


}