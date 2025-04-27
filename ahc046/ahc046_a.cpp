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
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> constexpr T INF() { return numeric_limits<T>::max(); }
template<class T> constexpr T HINF() { return INF<T>() / 2; }
const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

struct INIT {
    INIT() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

const char dc[4] = {'U', 'D', 'L', 'R'};
int n, m;
vector<vector<bool>> grid;
int nowTurn;
int ci, cj;
vector<pair<char, char>> ans;
const int maxTurn = 2 * 20 * 40;
set<pair<int, int>> blocks;

void move(int dir){
    ans.push_back({'M', dc[dir]});
    ci += di[dir];
    cj += dj[dir];
    nowTurn++;
}

pair<int, int> slide(int dir, bool execute){
    if (execute) ans.push_back({'S', dc[dir]});
    int i = ci, j = cj;
    while (true){
        int ni = i + di[dir];
        int nj = j + dj[dir];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n) break;
        if (grid[ni][nj]) break;
        i = ni;
        j = nj;
    }
    if (execute){
        ci = i;
        cj = j;
        nowTurn++;
    }
    return {i, j};
}

void toggle(int dir){
    ans.push_back({'A', dc[dir]});
    int ti = ci + di[dir];
    int tj = cj + dj[dir];
    if (0 <= ti && ti < n && 0 <= tj && tj < n) {
        grid[ti][tj] = !grid[ti][tj];
        if (grid[ti][tj]) blocks.insert({ti, tj});
        else blocks.erase({ti, tj});
    }
    nowTurn++;
}

bool block_needed(pair<int, int> block){
    rep(d, 4) {
        int x = block.first, y = block.second;
        while (true) {
            int nx = x + di[d], ny = y + dj[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
            if (grid[nx][ny]) break;
            if (make_pair(nx, ny) == make_pair(ci, cj)) return true;
            x = nx;
            y = ny;
        }
    }
    return false;
}

bool is_near_center(int i, int j){
    return (9 <= i && i <= 11) || (9 <= j && j <= 11);
}

void place_wall_around(){
    vector<int> candidates;
    rep(dir, 4) {
        int ni = ci + di[dir], nj = cj + dj[dir];
        if (0 <= ni && ni < n && 0 <= nj && nj < n && !grid[ni][nj]) {
            candidates.push_back(dir);
        }
    }
    if (!candidates.empty()) {
        int dir = candidates[rand() % candidates.size()];
        toggle(dir);
    }
}

int main(){
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    rep(i, m) cin >> p[i].first >> p[i].second;

    grid.assign(n, vector<bool>(n, false));
    ci = p[0].first;
    cj = p[0].second;
    nowTurn = 0;

    for (int k = 1; k < m && nowTurn < maxTurn; k++){
        int ni = p[k].first;
        int nj = p[k].second;

        if (is_near_center(ni, nj)) place_wall_around();

        while ((ci != ni || cj != nj) && nowTurn < maxTurn){
            for (auto it = blocks.begin(); it != blocks.end(); ){
                if (!block_needed(*it)) {
                    int bi = it->first, bj = it->second;
                    rep(dir, 4) {
                        if (ci + di[dir] == bi && cj + dj[dir] == bj){
                            toggle(dir);
                            break;
                        }
                    }
                    it = blocks.erase(it);
                } else {
                    it++;
                }
            }

            int nowdist = abs(ci - ni) + abs(cj - nj);
            int bestdir = -1;
            int bestdist = nowdist;
            rep(dir, 4) {
                auto [si, sj] = slide(dir, false);
                int dist = abs(si - ni) + abs(sj - nj);
                if (dist < bestdist) {
                    bestdist = dist;
                    bestdir = dir;
                }
            }

            if (bestdir != -1) {
                auto [si, sj] = slide(bestdir, false);
                if (grid[si][sj]) toggle(bestdir);
                slide(bestdir, true);
                continue;
            }

            int dir;
            if (ci < ni) dir = 1;
            else if (ci > ni) dir = 0;
            else if (cj < nj) dir = 3;
            else dir = 2;

            int ni2 = ci + di[dir], nj2 = cj + dj[dir];
            if (0 <= ni2 && ni2 < n && 0 <= nj2 && nj2 < n && grid[ni2][nj2]) {
                toggle(dir);
            }
            move(dir);
        }
    }

    for (auto [i, j] : ans) {
        cout << i << ' ' << j << endl;
    }
    return 0;
}
