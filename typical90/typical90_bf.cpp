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

ll digsum(ll n) {
    int res = 0;
    while(n > 0) {
       res += n%10;
       n /= 10;
    }
return res;
}

const ll mod = 100000;
ll n, k;

int main() {
    cin >> n >> k;
    vector<ll> cal(mod);
    rep(i, mod){
        cal[i] = (i + digsum(i))%mod;
    }

    vector<int> seen(mod, -1);
    ll now = n;
    ll cnt = 0;
    while(true){
        if(seen[now] != -1) break;
        seen[now] = cnt;
        now = cal[now];
        cnt++;
    }

    ll cycle = cnt - seen[now];
    if(k >= seen[now]){
        k = (k - seen[now])%cycle + seen[now];
    }
    ll ans = -1;
    rep(i, mod){
        if(seen[i] == k){
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;

}