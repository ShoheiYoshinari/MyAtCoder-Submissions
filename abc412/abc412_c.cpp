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

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        rep(i, n) cin >> a[i];

        ll st = a[0];
        ll en = a[n-1];
        if(st*2 >= en){
            cout << 2 << endl;
            continue;
        }

        vector<int> b;
        rep(i, 1, n-1) b.push_back(a[i]);
        sort(all(b));

        ll now = st;
        ll cnt = 2;
        bool ok = false;
        while(1){
            auto it = upper_bound(all(b), now*2);
            if(it == b.begin()){
                cout << -1 << endl;
                ok = true;
                break;
            }

            --it;
            now = *it;
            b.erase(it);
            cnt++;
            if(now*2 >= en){
                cout << cnt << endl;
                ok = true;
                break;
            }
        }
        if(!ok) cout << -1 << endl;
    }
}