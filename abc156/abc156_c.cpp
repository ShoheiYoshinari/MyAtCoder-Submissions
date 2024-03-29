#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
   int n;
   cin >> n;
   vector<int> x(n);
   rep(i, n) cin >> x[i];

   int minp = 100000009;
   for(int i = 0; i <= 100; i++){
      int ans = 0;
      rep(j, n){
         ans += (x[j] - i)*(x[j] - i);
      }
      minp = min(minp, ans);
   }
   cout << minp << endl;
}