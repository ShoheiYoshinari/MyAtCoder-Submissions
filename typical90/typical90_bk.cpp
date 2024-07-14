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

ll h, w;
ll p[19][100009];

int max_same(vector<int> cho){
    map<int, int> mp;
    int ret = 0;
    rep(i, cho.size()){
        mp[cho[i]]++;
        chmax(ret, mp[cho[i]]);
    }
    return ret;
}

int main() {
    cin >> h >> w;
    rep(i, h) rep(j, w) cin >> p[i][j];

    int ans = 0;
    rep(i, (1<<h)){
        vector<int> cho;
        rep(j, w){
            int idx = -1;
            bool flag = true;
            rep(k, h){
                if((i&(1<<k)) == 0) continue;
                if(idx == -1) idx = p[k][j];
                else if(idx != p[k][j]) flag = false;
            }
            if(flag) cho.push_back(idx);
        }

        int cnth = 0, cntw = max_same(cho);
        rep(j, h){
        if((i&(1<<j)) != 0) cnth++;
        }
        //cout << cnth << " " << cntw << endl;
        chmax(ans, cnth*cntw);
    }
    cout << ans << endl;
    return 0;
}