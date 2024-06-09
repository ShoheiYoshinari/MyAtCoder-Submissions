#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
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

vector<int> memo(100009, 0);
vector<int> s(100009, 0);

bool isPrime(int x){
   int i;
   if(x < 2)return 0;
   else if(x == 2) return 1;
   if(x%2 == 0) return 0;
   for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
   return 1;
}

int main(){
    int q;
    cin >> q;
    rep(i, 100009){
        if(isPrime(i) == 1 && isPrime((i+1)/2)) memo[i] = 1;
    }
    rep2(i, 1, 100000) s[i] = s[i-1] + memo[i];
    rep(i, q){
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
}