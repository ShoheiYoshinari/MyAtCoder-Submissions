#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    ll now = 1;
    ll cnt = 0;
    vector<ll> seen(n+1, -1);
    while(true){
        //cout << now << endl;
        if(seen[now] != -1) break;
        seen[now] = cnt;
        now = a[now];
        cnt++;
    }

    ll cycle = cnt - seen[now];
    //cout << cycle << endl;
    if(k >= seen[now]){
        k = (k - seen[now])%cycle + seen[now];
    }
    //cout << k << endl;

    ll ans = -1;
    rep(i, 1, n+1){
        if(seen[i] == k){
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}