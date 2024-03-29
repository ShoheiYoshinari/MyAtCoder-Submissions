#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n;
    cin >> n;
    for(int i = 9; i >= 0; i--){
        int wari = (1 << i);
        cout << (n/wari) % 2;
    }
    cout << endl;
}