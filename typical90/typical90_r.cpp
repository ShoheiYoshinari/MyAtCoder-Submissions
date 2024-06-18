#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const long double pi = acos(-1);
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
    long double t;
    cin >> t;
    long double l, x, y;
    cin >> l >> x >> y;

    int q;
    cin >> q;
    rep(i, q){
        long double e;
        cin >> e;

        long double deg = e/t*2.0*pi;
        long double sx = 0.0;
        long double sy = -(l/2.0)*sin(deg);
        long double sz = (l/2.0) - (l/2.0)*cos(deg);

        long double a = sqrt((sx-x)*(sx-x) + (sy-y)*(sy-y));
        long double b = sz;
        long double hukaku = atan2(b, a);
        cout << hukaku * 180.0l / pi << endl;
    }
    return 0;
}