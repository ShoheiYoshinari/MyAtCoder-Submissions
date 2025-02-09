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
  cout << fixed << setprecision(15);
 }
}INIT;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> dice(n);
    vector<unordered_map<int, int>> count(n);
    
    rep(i, n) {
        int k;
        cin >> k;
        dice[i].resize(k);
        rep(j, k) {
            cin >> dice[i][j];
            count[i][dice[i][j]]++;
        }
    }
    
    double max_prob = 0.0;
    
    rep(i, n) {
        rep(j, i+1, n) {
            double prob = 0.0;
            for (const auto& entry : count[i]) {
                int value = entry.first;
                if (exists(count[j], value)) {
                    prob += (double)(entry.second) / dice[i].size() * (double)(count[j][value]) / dice[j].size();
                }
            }
            chmax(max_prob, prob);
        }
    }
    
    cout << max_prob << endl;
    
    return 0;
}
