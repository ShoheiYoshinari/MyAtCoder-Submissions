#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main(){
   int a, b;
   cin >> a >> b;
   if(a * b %2 == 0){
      cout << "Even" << endl;
   }else{
      cout << "Odd" << endl;
   }
}