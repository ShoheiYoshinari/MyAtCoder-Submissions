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
    int n, k;
    cin >> n >> k;
    k--;
    string s;
    cin >> s;

    vector<pair<string, int>> zero, one;
    int cnt = 0;
    string tmp = "";
    tmp += s[0];
    rep(i, (int)s.size()-1){
        if(s[i] != s[i+1]) {
            if(tmp[0] == '0') zero.push_back({tmp, cnt});
            else one.push_back({tmp, cnt});
            cnt++;
            tmp = s[i+1];
        }else{
            tmp += s[i+1];
        }
    }
    if(tmp[0] == '0') zero.push_back({tmp, cnt});
    else one.push_back({tmp, cnt});
    cnt++;

    one[k-1].first += one[k].first;
    one[k].first = "";

    int cnt2 = 0;
    int zero_cnt = 0, one_cnt = 0;
    rep(i, cnt){
        if(cnt2 == zero[zero_cnt].second){
            cout << zero[zero_cnt].first;
            zero_cnt++;
        }else{
            cout << one[one_cnt].first;
            one_cnt++;
        }
        cnt2++;
    }
    cout << endl;
    return 0;
}