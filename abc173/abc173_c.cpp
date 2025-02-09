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
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> s(h, vector<char>(w));
    int black = 0;
    rep(i, h) rep(j, w){
        cin >> s[i][j];
        if(s[i][j] == '#') black++;
    }


    int ans = 0;
    rep(i, (1<<h)){
        rep(j, (1<<w)){
            vector<int> rows, cols;
            rep(k, h) if(i&(1<<k)) rows.push_back(k);
            rep(k, w) if(j&(1<<k)) cols.push_back(k);

            int cnt = 0;
            rep(r, rows.size()){
                rep(c, w){
                    if(s[rows[r]][c] == '#') cnt++;
                }
            }
            rep(r, h){
                rep(c, cols.size()){
                    if(s[r][cols[c]] == '#') cnt++;
                }
            }
            rep(r, rows.size()){
                rep(c, cols.size()){
                    if(s[rows[r]][cols[c]] == '#') cnt--;
                }
            }
            if(black - cnt == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}