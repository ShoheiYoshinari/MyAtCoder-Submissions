#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int a ,b;
    cin >> a >> b;
    
    int base = 0;
    for(int i = 1; i <= b-a; i++){
        base += i;
    }
    cout << base - b << endl;
}
