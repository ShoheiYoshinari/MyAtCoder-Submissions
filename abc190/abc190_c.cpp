#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);

// 最小値と最大値を更新するテンプレート関数
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

// 初期化構造体
struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

int main() {
    int n, m, k;
    cin >> n >> m;
    vector<pair<int, int>> both;
    both.reserve(m);  // サイズの予約
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        both.emplace_back(a, b);
    }
    cin >> k;
    vector<pair<int, int>> boll;
    boll.reserve(k);  // サイズの予約
    rep(i, k) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        boll.emplace_back(c, d);
    }

    int ans = 0;
    rep(i, 1 << k) {
        vector<bool> placed(n, false);
        rep(j, k) {
            if (i & (1 << j)) placed[boll[j].first] = true;
            else placed[boll[j].second] = true;
        }

        int cnt = 0;
        rep(j, m) {
            if (placed[both[j].first] && placed[both[j].second]) cnt++;
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
