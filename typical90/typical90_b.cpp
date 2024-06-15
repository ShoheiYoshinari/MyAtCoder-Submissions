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

    for(int i = (1<<n)-1; i >= 0; i--){
        string str = "";
        vector<int> res;
        rep(j, n){
            if(i & (1 << j)){
                str = '(' + str;
                res.push_back(1);
            }else{
                str = ')' + str;
                res.push_back(0);
            }
        }

        vector<int> ans;
        for(auto c : res){
            if(!ans.empty() && ans.back() != c && c == 1){
                ans.pop_back();
            }else{
                ans.push_back(c);
            }
        }
        if(ans.empty()) cout << str << endl;
    }
}