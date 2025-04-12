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
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

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

    int si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;
    si--, sj--, ti--, tj--;

    vector dist(h, vector<int>(w, HINF<int>()));
    vector seen(h, vector<bool>(w));
    deque<pair<int, int>> q;

    auto push = [&](int i, int j, int d, int cost){
        if(dist[i][j] <= d) return;
        dist[i][j] = d;

        if(cost == 0) q.emplace_front(i, j);
        else q.emplace_back(i, j);
    };

    push(si, sj, 0, 0);
    while(!q.empty()){
        auto [i, j] = q.front(); q.pop_front();
        if(seen[i][j]) continue;
        seen[i][j] = true;

        int d = dist[i][j];
        rep(dir, 4){
            int ni = i+di[dir], nj = j+dj[dir];
            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if(s[ni][nj] == '.') push(ni, nj, d, 0);
        }
        rep(dir, 4){
            int ni = i, nj = j;
            rep(k, 2){
                ni += di[dir], nj += dj[dir];
                if(ni < 0 || ni >= h || nj < 0 || nj >= w) break;
                push(ni, nj, d+1, 1);
            }
        }
    }
    cout << dist[ti][tj] << endl;
    return 0;
}