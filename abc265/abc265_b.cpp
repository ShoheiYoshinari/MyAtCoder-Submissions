#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
   int n, m; 
   long long t;
   cin >> n >> m >> t;
   vector<int> a(n-1), b(n);
   rep(i, n-1) {
      cin >> a[i];
   }
   rep(i, m) {
      int x, y;
      cin >> x >> y;
      b[x-1] = y;
   }

   rep(i, n){
      t += b[i];
      t -= a[i];
      if(t <= 0){
         cout << "No" << endl;
         return 0;
      }
   }
   cout << "Yes" << endl;




   
}