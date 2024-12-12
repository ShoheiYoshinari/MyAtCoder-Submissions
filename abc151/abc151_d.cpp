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

using Grapg = vector<vector<int>>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int max_dist = -1;
    rep(i, h) rep(j, w){
        if(s[i][j] == '#') continue;
        vector<vector<int>> dist(h, vector<int> (w, -1));
        queue<pair<int, int>> que;

        dist[i][j] = 0;
        que.push({i, j});
        while(!que.empty()){
            int r = que.front().first;
            int c = que.front().second; que.pop();
            rep(dir, 4){
                int nr = r + dy[dir];
                int nc = c + dx[dir];
                if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
                if(s[nr][nc] == '#') continue;
                if(dist[nr][nc] != -1) continue;
                dist[nr][nc] = dist[r][c] + 1;
                que.push({nr, nc});
                chmax(max_dist, dist[nr][nc]);
            }
        }
    }
    cout << max_dist << endl;
    return 0;
}