#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

int n, m;
ll l;
vector<string> s;
vector<int> p;

int main() {
    cin >> n >> m >> l;
    s.resize(n);
    p.resize(n);
    rep(i, n) cin >> s[i] >> p[i];

    map<char, ll> weight;
    rep(i, n) {
        set<char> st;
        for (auto c : s[i]) {
            if (st.insert(c).second) {
                weight[c] += p[i];
            }
        }
    }

    vector<char> c(m);
    rep(i, m) {
        c[i] = char('a' + (i % 6));
    }

    vector<vector<int>> a(m, vector<int>(m, 0));
    vector<pair<ll, int>> order;
    order.resize(m);

    rep(i, m) {
        vector<ll> raw(m);
        ll sum_raw = 0;
        rep(j, m) {
            raw[j] = weight[c[j]] + 1;
            sum_raw += raw[j];
        }

        int base_sum = 0;
        rep(j, m) {
            a[i][j] = raw[j] * 100 / sum_raw;
            base_sum += a[i][j];
            order[j] = {raw[j], j};
        }

        int rem = 100 - base_sum;
        sort(all(order), greater<>());
        rep(k, rem) {
            int idx = order[k].second;
            a[i][idx]++;
        }
    }

    rep(i, m) {
        cout << c[i];
        rep(j, m) {
            cout << ' ' << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
