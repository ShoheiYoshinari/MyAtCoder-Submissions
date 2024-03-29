#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
   int x, y, n;
   cin >> x >> y >> n;
   if(x*3 < y) cout << n*x << endl;
   else cout << (n/3)*y + (n%3)*x << endl;
} 