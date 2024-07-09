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

vector<vector<int>> s(1009, vector<int> (1009, 0));
int main() {
    int n;
    cin >> n;

    rep(i, n){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        s[lx][ly]++;
        s[lx][ry]--;
        s[rx][ly]--;
        s[rx][ry]++;
    }

    rep(i, 0, 1009){
        rep(j, 1, 1009){
            s[i][j] += s[i][j-1];
        }
    }
    rep(i, 1, 1009){
        rep(j, 0, 1009){
            s[i][j] += s[i-1][j];
        }
    }

    map<int, int> mp;
    rep(i, 0, 1001){
        rep(j, 0, 1001){
            mp[s[i][j]]++;
        }
    }

    rep(i, 1, n+1){
        cout << mp[i] << endl;
    }
    return 0;

}