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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    int q;
    cin >> q;
    rep(i, q){
        int b;
        cin >> b;
        int dif_low = lower_bound(a.begin(), a.end(), b) - a.begin();
        //int dif_up = upper_bound(a.begin(), a.end(), b) - a.begin();
        if(dif_low) cout << min(abs(a[dif_low]- b), abs(a[dif_low-1] - b)) << endl;
        else cout << abs(a[dif_low]- b) << endl;
    }
    return 0;
}