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
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> cnt[2];
    rep(i, n) cnt[i%2][a[i]]++;

    vector<pair<int, int>> v[2];
    rep(i, 2){
        for(auto &p : cnt[i]) v[i].push_back({p.second, p.first});
        sort(all(v[i]));
        reverse(all(v[i]));
    }

    if(v[0][0].second != v[1][0].second){
        cout << n - v[0][0].first - v[1][0].first << endl;
        return 0;
    }

    if(v[0].size() == 1 && v[1].size() == 1){
        cout << n / 2 << endl;
        return 0;
    }

    int ans = INF<int>();
    if(2 <= v[0].size()) chmin(ans, n - v[0][1].first - v[1][0].first);
    if(2 <= v[1].size()) chmin(ans, n - v[0][0].first - v[1][1].first);
    cout << ans << endl;
    return 0;
}