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
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

struct INIT{
    INIT(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(20);
    }
}INIT;

int n, ti, tj;
vector<string> b;
set<pair<int, int>> forbidden, initial;

bool in_bounds(int i, int j){
    return (0 <= i && i < n && 0 <= j && j < n);
}

bool bfs_check() {
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int,int>> q;

    q.push({0, n/2});
    dist[0][n/2] = 0;

    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        rep(d, 4){
            int ni = i + di[d];
            int nj = j + dj[d];
            if(!in_bounds(ni, nj)) continue;
            if(b[ni][nj] == 'T') continue;
            if(dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni,nj});
        }
    }
    return dist[ti][tj] != -1;
}

bool can_place(int i, int j){
    if(!in_bounds(i, j)) return false;
    if(forbidden.count({i, j})) return false;
    if(b[i][j] == 'T') return false;
    return true;
}

//トレント初期配置
//花周辺
void place_flower_walls_trent(){
    int direction = -1;
    rep(dir, 4){
        int ni = ti + di[dir];
        int nj = tj + dj[dir];
        if(in_bounds(ni, nj) && b[ni][nj] != 'T'){
            direction = dir;
            break;
        }
    }
    if(direction == -1) return ;

    vector<pair<int, int>> offsets;
    if(direction == 0) offsets = {{0,-1},{0,1},{-1,0}};
    if(direction == 1) offsets = {{0,-1},{0,1},{1,0}};
    if(direction == 2) offsets = {{-1,0},{1,0},{0,1}};
    if(direction == 3) offsets = {{-1,0},{1,0},{0,-1}};

    for(auto [dx, dy] : offsets){
        int ni = ti + dx;
        int nj = tj + dy;
        if(!can_place(ni,nj)) continue;
        b[ni][nj] = 'T';
        if(!bfs_check()) { b[ni][nj] = '.'; continue; }
        initial.insert({ni,nj});
        forbidden.insert({ni,nj});
    }
}

//鎖状設置
void place_chain_pattern_trent(){
    bool one = false;
    bool odd = ti%2;
    for(int i = (int)odd; i < n; i += 2){
        rep(j, n){
            if((i+j+(int)one)%2 != (ti+tj)%2) continue;
            if(!can_place(i, j)) continue;
            b[i][j] = 'T';
            if(!bfs_check()){
                b[i][j] = '.';
                continue;
            }
            initial.insert({i, j});
            forbidden.insert({i, j});
        }
        //コメントアウトでブロック状
        one = !one;
    }
}

//縦方向に配置
void place_vertical_walls_trent() {
    random_device rd;
    mt19937 g(rd());
    vector<int> target_cols = {n/8, n/4, (3*n)/8, n/2, (5*n)/8, (3*n)/4, (7*n)/8};
    for(int col : target_cols) {
        vector<pair<int,int>> candidates;
        rep(i, n){
            if(can_place(i,col)) candidates.push_back({i,col});
        }
        shuffle(candidates.begin(), candidates.end(), g);
        int max_to_place = min((int)candidates.size(), n/4); //n/3 -> n/4
        rep(k, max_to_place){
            auto [x,y] = candidates[k];
            b[x][y] = 'T';
            if(!bfs_check()){
                b[x][y] = '.';
                continue;
            }
            initial.insert({x,y});
            forbidden.insert({x,y});
        }
    }
}

int main() {
    cin >> n;
    cin >> ti >> tj;
    b.resize(n);
    rep(i, n) cin >> b[i];

    // トレント設置禁止
    forbidden.insert({0, n/2});
    forbidden.insert({ti, tj});
    rep(i, n){
        rep(j, n){
            if(b[i][j] == 'T') forbidden.insert({i, j});
        }
    }

    place_flower_walls_trent();
    place_chain_pattern_trent();
    place_vertical_walls_trent();

    while(true){
        int pi, pj;
        cin >> pi >> pj;
        if (pi == ti && pj == tj) break;

        int nn;
        cin >> nn;
        rep(i, nn){
            int x, y;
            cin >> x >> y;
        }

        cout << initial.size();
        for(auto [x, y] : initial) cout << " " << x << " " << y;
        cout << endl;
        cout << -1 << endl;
        cout.flush();
        cerr << initial.size();
        for(auto [x, y] : initial) cerr << " " << x << " " << y;
        cerr << endl;
        cerr << -1 << endl;
        return 0;
    }
}
