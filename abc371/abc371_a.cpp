#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;
int main(){
    char x[3];
    rep(i, 3) cin >> x[i];
    int a = 0, b = 0, c = 0;
    rep(i, 3){
        if(x[i] == '<'){
            if(i == 0) b++;
            if(i == 1) c++;
            if(i == 2) c++;
        }else{
            if(i == 0) a++;
            if(i == 1) a++;
            if(i == 2) b++;
        }
    }
    if((a == 0 && c == 2)||(a == 2 && c == 0)) cout << 'B' << endl;
    else if((b == 0 && c == 2)||(c == 0 && b == 2)) cout << 'A' << endl;
    else cout << 'C' << endl;
    return 0;
}