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
    string n;
    ll k;
    cin >> n >> k;

    string b8 = n, b9 = "";

    while(k--){
        ll b10 = 0;
        int size = b8.size();
        //10 decimal num
        rep(i, size){
            b10 += (ll)(b8[i]-'0')*((ll)pow(8, size-i-1));
        }

        while(b10){
            b9 = to_string(b10%9) + b9;
            b10 /= 9;
        }

        rep(i, b9.size()){
            if(b9[i] == '8') b9[i] = '5';
        }
        b8 = b9;
        b9 = "";
    }
    if(b8 == ""){
        cout << 0 << endl;
        return 0;
    }
    bool is0 = true;
    rep(i, b8.size()){
        if(b8[i] == '0' && is0 == true) continue;
        cout << b8[i];
        is0 = false;
    }
    cout << endl;
    return 0;

}