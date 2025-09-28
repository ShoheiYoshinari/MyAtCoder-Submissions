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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> mp;
    bool ok = true;
    rep(i, n){
        if(a[i] != -1) mp[a[i]]++;
    }

    vector<int> c;
    rep(i, n){
        if(mp[a[i]] >= 2){
            cout << "No" << endl;
            return 0;
        }else if(mp[i+1] == 0){
            c.push_back(i+1);
        }
    }

    int pos = 0;
    rep(i, n){
        if(a[i] == -1){
            a[i] = c[pos];
            pos++;
        }
    }

    cout << "Yes" << endl;
    rep(i, n){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;

}