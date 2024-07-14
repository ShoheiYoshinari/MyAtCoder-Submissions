#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

bool search(int x1, int x2, int x3, int y1, int y2, int y3){
    int a = x1 - x2;
    int b = x1 - x3;
    int c = y1 - y2;
    int d = y1 - y3;

    return a*b+c*d == 0;
}

int main(){
    int x[3];
    int y[3];
    rep(i, 3) cin >> x[i] >> y[i];

    rep(i, 3){
        if(search(x[i%3], x[(i+1)%3], x[(i+2)%3], y[i%3], y[(i+1)%3], y[(i+2)%3])){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
        return 0;

}