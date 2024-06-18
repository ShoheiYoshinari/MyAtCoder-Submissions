#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
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

const ll a = 10000;
const ll b = 5000;
const ll c = 1000;
const ll y_max = 20000000;
int main() {
    int n, y;
    cin >> n >> y;

    rep(i, n){
        rep(j, n){
            ll sum = i*a + j*b;
            if(y < sum) continue;
            if(sum + (n-i-j)*c == y){
                cout << i << ' ' << j << ' ' << n-i-j << endl;
                return 0;
            }
        }
    }
    cout << -1 << ' ' << -1 << ' ' << -1 << endl;
    return 0;
}