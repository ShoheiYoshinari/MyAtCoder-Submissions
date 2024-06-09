#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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
    map<string, int> blue, red;
    int n, m;
    cin >> n;
    string tmp;
    rep(i, n){
        cin >> tmp;
        blue[tmp]++;
    }
    cin >> m;
    rep(i, m){
        cin >> tmp;
        red[tmp]++;
    }

    int max = 0;
    for(auto p : blue){
        if(max < (max, p.second - red[p.first])){
            max = p.second - red[p.first];
        }
    }
    cout << max << endl;
    return 0;
}