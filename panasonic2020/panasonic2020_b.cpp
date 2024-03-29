#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
   long long h, w;
   cin >> h >> w;
   if(h == 1 || w == 1){
      cout << 1 << endl;
      return 0;
   }
   if(h % 2 == 1 && w % 2 == 1){
      cout << (h * w)/2 + 1 << endl;
   }else{
      cout << (h * w)/2 << endl;
   }
}