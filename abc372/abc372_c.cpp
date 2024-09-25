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
int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ".." + s + "..";
    n += 4;

    int cnt = 0;
    rep(i, 2, n-2){
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
            cnt++;
        }
    }

    rep(i, q){
        int x; char c;
        cin >> x >> c;
        x++;
        if(x >= 2 && x < n-2){
            if(s[x-2] == 'A' && s[x-1] == 'B' && s[x] == 'C') cnt--;
            if(s[x-1] == 'A' && s[x] == 'B' && s[x+1] == 'C') cnt--;
            if(s[x] == 'A' && s[x+1] == 'B' && s[x+2] == 'C') cnt--;
        }
        
        s[x] = c;

        if(x >= 2 && x < n-2){
            if (s[x-2] == 'A' && s[x-1] == 'B' && s[x] == 'C') cnt++;
            if (s[x-1] == 'A' && s[x] == 'B' && s[x+1] == 'C') cnt++;
            if (s[x] == 'A' && s[x+1] == 'B' && s[x+2] == 'C') cnt++;
        }
        //cout << s << endl;
        cout << cnt << endl;
    }
    return 0;
}