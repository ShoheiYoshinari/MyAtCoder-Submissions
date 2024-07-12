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

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int,int> mp;
    int fpos = 0;
    int dist = 0;
    rep(i, n){
        mp[a[i]]++;
        while(true){
            //cout << mp.size() << endl;
            if(mp.size() > k){
                mp[a[fpos]]--;
                if(mp[a[fpos]] == 0) mp.erase(a[fpos]);
                fpos++;
                
            }else break;
        }
        //cout << i - fpos << endl;
        chmax(dist, i - fpos + 1);
    }
    cout << dist << endl;
    return 0;
}