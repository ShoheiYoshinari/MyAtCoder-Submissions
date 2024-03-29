#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main(){
     int a, b;
     cin >> a >> b;

     for(int i = a; i <= b; i++){
        if(100 % i == 0){
            cout << "Yes" << endl;
            return 0;
        }
     }
     cout << "No" << endl;
}