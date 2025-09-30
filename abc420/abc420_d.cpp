#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<int>> dista(h, vector<int>(w, HINF<int>()));
    vector<vector<int>> distb(h, vector<int>(w, HINF<int>()));
    bool ok = true;
    queue<tuple<int, int, bool>> q;
    rep(i, h) rep(j, w) if(s[i][j] == 'S'){
        dista[i][j] = 0;
        q.push({i, j, ok});
    }

    int d;
    while(!q.empty()){
        auto [i, j, ok] = q.front(); q.pop();
        if(ok) d = dista[i][j];
        else d = distb[i][j];

        if(s[i][j] == 'G'){
            cout << d << endl;
            return 0;
        }

        rep(dir, 4){
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if(s[ni][nj] == '#') continue;
            if(ok && s[ni][nj] == 'x') continue;
            if(!ok && s[ni][nj] == 'o') continue;

            bool nok = ok;
            if(s[ni][nj] == '?') nok = !ok;
            if(nok){
                if(dista[ni][nj] != HINF<int>()) continue;
                dista[ni][nj] = d+1;
            }else{
                if(distb[ni][nj] != HINF<int>()) continue;
                distb[ni][nj] = d+1;
            }
            q.push({ni, nj, nok});
        }
    }
    cout << -1 << endl;
    return 0;
}