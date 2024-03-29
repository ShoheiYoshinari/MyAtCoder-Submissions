#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
   int n, m, c;
   cin >> n >> m >> c;
   vector<int> b(m);
   rep(i, m) cin >> b[i];

   int a, cnt = 0;
   rep(i, n){
      int sum = c;
      rep(j, m){
         cin >> a;
         sum += b[j] * a;
      }
      if(sum > 0) cnt++;
   }
   cout << cnt << endl;
}