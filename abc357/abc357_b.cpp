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
    string s;
    cin >> s;
    int cnta = 0, cntb = 0;
    rep(i, s.size()){
        if(s[i] >= 'a' && 'z' >= s[i]) cnta++;
        if(s[i] >= 'A' && 'Z' >= s[i]) cntb++;
    }
    if(cnta > cntb){
        rep(i, s.size()){
            if(s[i] >= 'A' && 'Z' >= s[i]){
                cout << (char)(tolower(s[i]));
            }else cout << s[i];
        }
        cout << endl;
    }else{
        rep(i, s.size()){
            if(s[i] >= 'a' && 'z' >= s[i]){
                cout << (char)(toupper(s[i]));
            }else cout << s[i];
        }
        cout << endl;
    }
    return 0;
}