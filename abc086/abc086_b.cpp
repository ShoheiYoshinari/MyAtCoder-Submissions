#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
   int a, b;
   cin >> a >> b;
   int z = b, bsize = 0;
   while( z != 0){
      z /= 10;
      bsize++;
   }
   int  keta = 1;
   rep(i, bsize) keta *= 10;
   int h = a * keta + b;

   rep(i, 1000){
      int wari = i;
      if(h == wari * wari){
         cout << "Yes" << endl;
         return 0;
      }
   }
   cout << "No" << endl;
}