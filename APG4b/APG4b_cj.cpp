#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;

  vector<int> vec(N);
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    cin >> vec.at(i);
    sum += vec.at(i);
  }


  for (int i = 0; i < N; i++)
  {
    if(vec.at(i) > sum / N){
        cout << vec.at(i) - sum/N << endl;
    }else{
        cout << sum/N - vec.at(i) << endl;
    }
  }
}