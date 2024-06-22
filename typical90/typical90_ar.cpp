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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int sift;
    for(int i = 1e5*2; i >= 0; i--){
        if(i%n == 0){
            sift = i;
            break;
        }
    }
    rep(i, q){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            x--; y--;
            swap(a[(x+sift)%n], a[(y+sift)%n]);
        }else if(t == 2){
            sift--;
        }else if(t == 3){
            x--;
            cout << a[(x+sift)%n] << endl;
        }
    }
    return 0;
}