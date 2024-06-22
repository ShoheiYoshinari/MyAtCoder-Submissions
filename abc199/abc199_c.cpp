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
    cin >> n;
    vector<char> s(2*n);
    rep(i, 2*n) cin >> s[i];
    cin >> q;

    bool shift = false;
    int sift = n;
    rep(i, q){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            a--, b--;
            if(shift) swap(s[(a+sift)%(2*n)], s[(b+sift)%(2*n)]);
            else swap(s[a], s[b]);
        }else if(t == 2){
            shift = !shift;
        }
    }

    if(shift){
        rep(i, 2*n){
            cout << s[(i+sift)%(2*n)];
        }
    }else{
        rep(i, 2*n){
            cout << s[i%(2*n)];
        }
    }
    cout << endl;
    return 0;

}