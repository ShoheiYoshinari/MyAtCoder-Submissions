#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()

template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

long double distance(pair<long double, long double> p1, pair<long double, long double> p2) {
    long double dx = p1.first - p2.first;
    long double dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n, s, t;
    cin >> n >> s >> t;

    vector<pair<long double, long double>> st(n), e(n);
    rep(i, n) {
        cin >> st[i].first >> st[i].second >> e[i].first >> e[i].second;
    }

    long double min_time = 1e9;
    vector<int> p(n);
    rep(i, n) p[i] = i;

    do {
        for (int bit = 0; bit < (1 << n); ++bit) {
            long double total_time = 0;
            pair<long double, long double> cur = {0, 0};

            rep(i, n) {
                int idx = p[i];
                pair<long double, long double> next_point;
                if (bit & (1 << i)) {
                    next_point = e[idx];
                } else {
                    next_point = st[idx];
                }

                total_time += distance(cur, next_point) / s;

                if (bit & (1 << i)) {
                    total_time += distance(e[idx], st[idx]) / t;
                    cur = st[idx];
                } else {
                    total_time += distance(st[idx], e[idx]) / t;
                    cur = e[idx];
                }
            }

            chmin(min_time, total_time);
        }
    } while (next_permutation(all(p)));

    cout << min_time << endl;

    return 0;
}
