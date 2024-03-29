#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int maximum = max(max(A,B),C);
  int minimum = min(min(A,B),C);

  cout << maximum - minimum << endl;
}