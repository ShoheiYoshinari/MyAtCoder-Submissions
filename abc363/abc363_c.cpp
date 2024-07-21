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
    string s;
    cin >> s;
    vector<char> c;
    rep(i, n) c.push_back(s[i]);

    ll cnt = 0;
    sort(all(c));
    do{
        string str = "";
        rep(i, n) str.push_back(c[i]);
        bool ok = true;
        for(int i = 0; i <= n-k; i++){
            bool flag = true;
            for(int j = 0; j < k; j++){
                if(str[i+j] != str[i+k-1-j]){
                    flag = false;
                }
            }
            if(flag) ok = false;
        }
        if(ok) cnt++;

    }while(next_permutation(all(c)));

    cout << cnt << endl;
    return 0;
}