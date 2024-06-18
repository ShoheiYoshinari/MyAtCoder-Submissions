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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    int ans = 19;
    rep(i, 1<<n){
        vector<int> dict;
        rep(j, n){
            if(i & (1<<j)){
                dict.push_back(j);
            }
        }
        set<int> st;
        for(auto j : dict){
            rep(k, s[j].size()){
                if(s[j][k] == 'o') st.insert(k);
            }
        }
        if(st.size() == m){
            chmin(ans, (int)dict.size());
        }
    }
    cout << ans << endl;
    return 0;
}