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
    int n;
    cin >> n;
    vector<pair<int,int>> task;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        task.emplace_back(b, a);
    }
    sort(all(task));

    int time = 0;
    bool ok = true;
    rep(i, n){
        if(time + task[i].second > task[i].first){
            ok = false;
            break;
        }else{
            time += task[i].second;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;


}