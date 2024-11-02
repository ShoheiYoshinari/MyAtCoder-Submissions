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

int H, W, K;
ll cnt = 0;
vector<string> grid;
vector<vector<bool>> visited;
void dfs(int x, int y, int step) {
    if (step == K) {
        cnt++;
        return;
    }
    visited[x][y] = true;
    rep(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < H && ny >= 0 && ny < W && grid[nx][ny] == '.' && !visited[nx][ny]) {
            dfs(nx, ny, step + 1);
        }
    }
    visited[x][y] = false;
}

int main(){
    cin >> H >> W >> K;
    grid.resize(H);
    rep(i, H) cin >> grid[i];

    visited.assign(H, vector<bool>(W, false));

    rep(i, H){
        rep(j, W){
            if(grid[i][j] == '.'){
                dfs(i, j, 0);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}