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
struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int H, W, D;
    cin >> H >> W >> D;
    
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(H, vector<int>(W, -1));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'H') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    int humid_count = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (grid[x][y] == '.' || grid[x][y] == 'H') {
            humid_count++;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                if (dist[nx][ny] <= D) {
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << humid_count << endl;
    return 0;
}
