#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
   int a, b;
   cin >> a >> b;
   int cnt = 1, ans = 0;
   while(cnt < b){
      cnt += a-1;
      ans ++;
   }
   cout << ans << endl;
}