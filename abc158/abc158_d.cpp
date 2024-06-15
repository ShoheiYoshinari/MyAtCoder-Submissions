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
    deque<char> deq;
    string s;
    cin >> s;
    rep(i, s.size()) deq.push_back(s[i]);
    int q;
    cin >> q;

    int t, f;
    char c;
    int cnt = 0;
    rep(i, q){
        cin >> t;
        if(t == 1){
            cnt++;
        }else{
            cin >> f >> c;
            if(f == 1){
                if(cnt%2 == 0) deq.push_front(c);
                else deq.push_back(c);
            }else if(f == 2){
                if(cnt%2 == 0) deq.push_back(c);
                else deq.push_front(c);
            }
        }
    }
    if(cnt%2 == 0){
        rep(i, deq.size()) cout << deq[i];
    }else{
        for(int i = deq.size()-1; i >= 0; i--) cout << deq[i];
    }
    cout << endl;
    return 0;
}