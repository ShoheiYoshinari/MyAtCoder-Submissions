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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    vector<int> l(m, -1), r(m, -1);
    int now = 0;
    rep(i, m){
        while(now < n && a[now] != b[i]) now++;
        if(now == n){
            cout << "No" << endl;
            return 0;
        }
        l[i] = now;
        now++;
    }

    now = n-1;
    for(int i = m-1; i >= 0; i--){
        while(now >= 0 && a[now] != b[i]) now--;
        if(now < 0){
            cout << "No" << endl;
            return 0;
        }
        r[i] = now;
        now--;
    }

    bool ok = false;
    rep(i, m){
        if(l[i] < r[i]){
            ok = true;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}