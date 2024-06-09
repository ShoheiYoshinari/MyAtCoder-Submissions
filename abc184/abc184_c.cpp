#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

const ll r = 1e9;

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int r = r2-r1, c=c2-c1;

    if(r == 0 && c== 0) cout << 0 << endl;
    else if(abs(r)+abs(c) <= 3 || r == c || r == -c) cout << 1 << endl;
    else if((r^c^1)&1 || abs(r-c) <= 3 || abs(r+c) <= 3 || abs(r)+abs(c) <= 6) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}