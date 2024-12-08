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

struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

int main() {
    int H, W, D;
    cin >> H >> W >> D;

    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<pair<int, int>> F;
    rep(i, H) rep(j, W) if (S[i][j] == '.') F.emplace_back(i, j);

    int res = 0;
    rep(i, F.size()) rep(j, i + 1, F.size()) {
        auto [x1, y1] = F[i];
        auto [x2, y2] = F[j];
        set<pair<int, int>> Hm;
        rep(x, H) rep(y, W) {
            if (S[x][y] == '.') {
                int d1 = abs(x - x1) + abs(y - y1);
                int d2 = abs(x - x2) + abs(y - y2);
                if (d1 <= D || d2 <= D) Hm.emplace(x, y);
            }
        }
        chmax(res, (int)Hm.size());
    }

    cout << res << endl;
    return 0;
}
