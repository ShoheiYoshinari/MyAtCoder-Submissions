#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
   int x, y, z;
   cin >> x >> y >> z;
   if(y < 0){
      x = -x;
      y = -y;
      z = -z;
   }
   if(x < y){
      cout << abs(x) << endl;
   }else{
      if(z > y){
         cout << "-1" << endl;
      }else{
         cout << abs(z) + abs(x-z) << endl;
      }
   }

}