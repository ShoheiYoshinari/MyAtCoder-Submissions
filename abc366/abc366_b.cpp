#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) < (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) <= (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
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
    int n;
    cin >> n;
    int m = 0;
    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
        chmax(m, (int)s[i].size());
    }

    rep(i, n){
        for(int j = (int)s[i].size(); j < m; j++){
            s[i] += '*';
        }
    }

    for(int j = m-1; j >= 0; j--){
        rep(i, n){
            if(s[i][j] == '*') s[i][j] = ' ';
            else break;
        }
    }

    rep(j, m){
        for(int i = n-1; i >= 0; i--){
            if(j > s[i].size()) break;
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}