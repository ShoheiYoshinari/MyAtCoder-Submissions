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
    string s, t = "";
    cin >> s;
    ll q;
    cin >> q;
    
    vector<ll> bi;
    bi.push_back(1);
    rep(i, 60) bi.push_back(bi[i]*2);

    rep(i, s.size()){
        if(s[i] >= 'A' && s[i] <= 'Z') t += (s[i] + 'a' - 'A');
        else t += (s[i] + 'A' - 'a');
    }

    rep(i, q){
        ll k;
        cin >> k; k--;
        ll cnt = k / (ll)s.size();
        ll m = k % (ll)s.size();
        bool b = true;

        while(cnt >= 1){
            rep(i, 61){
                if(cnt < bi[i]){
                    cnt -= bi[i-1];
                    b = !b;
                    break;
                }
            }
        }

        if(b) cout << s[m] << ' ';
        else cout << t[m] << ' ';
    }
    cout << endl;
    return 0;
}