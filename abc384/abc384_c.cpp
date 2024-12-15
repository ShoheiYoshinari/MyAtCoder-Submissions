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

bool compare(const pair<int, string>& a, std::pair<int, string>& b) {
    if (a.first != b.first)
        return a.first > b.first; // first を昇順で比較
    return a.second < b.second;  // second を昇順で比較
}

int main(){
    vector<int> p(5);
    rep(i, 5) cin >> p[i];

    vector<pair<int, string>> ans;
    rep(i, 1<<5){
        pair<int, string> tmp;
        rep(j, 5){
            int wari = 1 << j;
            if(i&(1<<j)){
               tmp.first += p[j];
               tmp.second += (char)('A'+j);
            }
        }
        ans.push_back(tmp);
    }
    sort(all(ans), compare);


    for(auto& i : ans) cout << i.second << endl;
    return 0;

}