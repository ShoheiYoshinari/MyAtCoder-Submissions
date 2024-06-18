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
    long double a, b, x;
    cin >> a >> b >> x;

    long double S = x/a;
    if(S <= a*b/2){
        cout << atan2(b, 2*S/b) * 180.0l / pi << endl;
    }else{
        long double h = (a*b-S)*2/a;
        cout << atan2(h, a) * 180.0l / pi << endl;
    }
    return 0;
}