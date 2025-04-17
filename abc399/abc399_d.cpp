#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for(auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for(auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b){ a = b; return true; } return false; }
template<class T> constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T> constexpr T HINF() { return INF<T>() / 2; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
    INIT(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int size = 2*n;
        vector<int> a(size);
        vector<pair<int, int>> co(n+1, {size, -1});
        rep(i, size){
            cin >> a[i];
            int x = a[i];
            if(i < co[x].first) co[x].first = i;
            if(i > co[x].second) co[x].second = i;
        }

        //隣接してないco
        vector<pair<int, int>> valid;
        rep(x, 1, n+1){
            if(co[x].second - co[x].first > 1)
                valid.push_back({co[x].first, co[x].second});
        }
        sort(all(valid));

        if(valid.size() < 1){
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;
        for(int i = 0; i < valid.size()-1; i++){
            if(abs(valid[i].first-valid[i+1].first) <= 1 && abs(valid[i].second-valid[i+1].second) <= 1){
                ans++;
            }
        }
        cout << ans << endl;
    }
}
