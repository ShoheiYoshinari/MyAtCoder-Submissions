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

    vector<vector<int>> d(h, vector<int>(w, HINF<int>()));
    queue<pair<int, int>> q;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#'){
                d[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int ans = 0;
    while(!q.empty()){
        ans++;
        auto [i, j] = q.front(); q.pop();
        int st = d[i][j];
        rep(dir, 4){
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if(d[ni][nj] != HINF<int>()) continue;
            
            int cnt = 0;
            rep(dir2, 4){
                int mi = ni + di[dir2];
                int mj = nj + dj[dir2];
                if(mi < 0 || mi >= h || mj < 0 || mj >= w) continue;
                if(d[mi][mj] <= st) cnt++;
            }
            if(cnt == 1){
                d[ni][nj] = st + 1;
                q.push({ni, nj});
            }
        }
    }
    cout << ans << endl;
    return 0;
}