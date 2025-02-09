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
template<class T> constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T> constexpr T HINF() { return INF<T>() / 2; }

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

vector<pair<int, int>> find_oni_positions(const vector<string>& C, int N) {
    vector<pair<int, int>> oni_positions;
    rep(i, N) rep(j, N) if(C[i][j] == 'x') oni_positions.push_back({i, j});

    sort(all(oni_positions), [&](const pair<int, int>& a, const pair<int, int>& b){
        int dist_a = min({a.first, a.second, N - a.first - 1, N - a.second - 1});
        int dist_b = min({b.first, b.second, N - b.first - 1, N - b.second - 1});
        return dist_a < dist_b;
    });
    return oni_positions;
}

void record_operations(const vector<pair<int, int>>& oni_positions, const vector<string>& C, vector<pair<string, int>>& operations, int N) {
    for(auto& pos : oni_positions) {
        int i = pos.first, j = pos.second;

        bool no_o_above = true;
        rep(k, i) if (C[k][j] == 'o') { no_o_above = false; break; }
        if(no_o_above) {
            rep(k, i + 1) operations.push_back({"U", j});
            rep(k, i + 1) operations.push_back({"D", j});
        }else{
            bool no_o_below = true;
            rep(k, i + 1, N) if (C[k][j] == 'o') { no_o_below = false; break; }
            if (no_o_below) {
                rep(k, i, N) operations.push_back({"D", j});
                rep(k, i, N) operations.push_back({"U", j});
            }else{
                bool no_o_left = true;
                rep(k, j) if (C[i][k] == 'o') { no_o_left = false; break; }
                if (no_o_left) {
                    rep(k, j + 1) operations.push_back({"L", i});
                    rep(k, j + 1) operations.push_back({"R", i});
                }else{
                    bool no_o_right = true;
                    rep(k, j + 1, N) if (C[i][k] == 'o') { no_o_right = false; break; }
                    if (no_o_right) {
                        rep(k, j, N) operations.push_back({"R", i});
                        rep(k, j, N) operations.push_back({"L", i});
                    }
                }
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<string> C(N);
    rep(i, N) cin >> C[i];

    vector<pair<string, int>> operations;
    vector<pair<int, int>> oni_positions = find_oni_positions(C, N);
    record_operations(oni_positions, C, operations, N);
    for (auto& op : operations) cout << op.first << " " << op.second << endl;
    return 0;
}
