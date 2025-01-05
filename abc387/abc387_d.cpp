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
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

const vector<pair<int, int>> tate = {{0, 1}, {0, -1}};
const vector<pair<int, int>> yoko = {{1, 0}, {-1, 0}};

struct INIT {
    INIT() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

using Graph = vector<string>;

int main() {
    int h, w;
    cin >> h >> w;
    Graph G(h);
    rep(i, h) cin >> G[i];

    int sr = -1, sc = -1, gr = -1, gc = -1;
    rep(i, h) rep(j, w) {
        if (G[i][j] == 'S') sr = i, sc = j;
        if (G[i][j] == 'G') gr = i, gc = j;
    }

    vector<vector<int>> dist(h, vector<int>(w, -1));
    vector<vector<int>> dist2(h, vector<int>(w, -1));
    queue<tuple<int, int, bool>> que;

    que.push({sr, sc, true});
    dist[sr][sc] = 0;

    while (!que.empty()) {
        auto [r, c, is_vertical] = que.front(); que.pop();

        const auto& directions = is_vertical ? tate : yoko;
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if (G[nr][nc] == '#') continue;
            if (dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[r][c] + 1;
            que.push({nr, nc, !is_vertical});
        }
    }

    que.push({sr, sc, false});
    dist2[sr][sc] = 0;

    while (!que.empty()) {
        auto [r, c, is_vertical] = que.front(); que.pop();

        const auto& directions = is_vertical ? tate : yoko;
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            if (G[nr][nc] == '#') continue;
            if (dist2[nr][nc] != -1) continue;

            dist2[nr][nc] = dist2[r][c] + 1;
            que.push({nr, nc, !is_vertical});
        }
    }
    if(dist[gr][gc] == -1 && dist2[gr][gc] == -1){
        cout << -1 << endl;
    }else if(dist[gr][gc] == -1 || dist2[gr][gc] == -1){
        cout << max(dist[gr][gc], dist2[gr][gc]) << endl;
    }else{
        cout << min(dist[gr][gc], dist2[gr][gc]) << endl;
    }
    return 0;
}
