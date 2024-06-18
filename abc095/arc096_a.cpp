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

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if(a + b <= c * 2){
        cout << a*x + b*y << endl;
    }else{
        ll max_half = max(x, y);
        ll min_half = min(x, y);
        ll candi1 = a*(x-min_half) + b*(y-min_half) + c*min_half*2;
        ll candi2 = c*max_half*2;
        cout << min(candi1, candi2) << endl;
        return 0;
    }
}