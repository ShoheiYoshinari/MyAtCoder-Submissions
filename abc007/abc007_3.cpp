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

using Graph = vector<vector<int>>;

int main(){
    int r, c, sy, sx, gy, gx;
    cin >> r >> c;
    cin >> sy >> sx;
    sy--, sx--;
    cin >> gy >> gx;
    gy--, gx--;

    vector<vector<char>> s(r, vector<char>(c));
    rep(i, r) rep(j, c) cin >> s[i][j];

    queue<pair<int, int>> que;
    Graph dist(r, vector<int> (c, -1));

    dist[sy][sx] = 0;
    que.push({sy, sx});

    while(!que.empty()){
        auto [i, j] = que.front(); que.pop();

        rep(dir, 4){
            auto ny = i + dy[dir];
            auto nx = j + dx[dir];

            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(dist[ny][nx] != -1) continue;
            if(s[ny][nx] != '.') continue;

            dist[ny][nx] = dist[i][j] + 1;
            que.push({ny, nx});
        }
    }
    cout << dist[gy][gx] << endl;
    return 0;
}