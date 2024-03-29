#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
   set<int> x;
   int a;
   rep(i, 5){
      cin >> a;
      x.insert(a);
   }
   cout << x.size() << endl;
}