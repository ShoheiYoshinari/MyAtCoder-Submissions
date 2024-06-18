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
    double a, b, h, m;
    cin >> a >> b >> h >> m;

    double deg_a = 2*pi*(h + m/60.0)/12.0;
    double deg_b = 2*pi*m/60.0;
    //cout << deg_a << endl;
    //cout << deg_b << endl;
    double deg = abs(deg_a - deg_b);

    if(deg > pi) deg = 2*pi - deg;
    //cout << deg << endl;
    double c = sqrt(a*a + b*b -2*a*b*cos(deg));
    cout << c << endl;
    return 0;
}
