#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;

  int count = 1;

  for(int i = 0; i < S.size(); i++){
    if(S.at(i) == '+'){
        count++;
        i++;
    }else if(S.at(i) == '-'){
        count--;
        i++;
    }
  }
  cout << count << endl;
}