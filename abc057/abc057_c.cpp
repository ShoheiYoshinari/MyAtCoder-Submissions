#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

int main(){
    ll n;
    cin >> n;

    int ans = to_string(n).size();
    int res;
    ll b;
    for(ll a = 1ll; a*a <= n; a++){
        if(n%a != 0) continue;
        b = n/a;

        res = max(to_string(a).size(), to_string(b).size());
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}