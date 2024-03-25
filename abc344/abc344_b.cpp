#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int a[109];
int main(){
    int n = 0;
    while(true){
        cin >> a[n];
        if(a[n] == 0) break;
        else n++;
    }

    for(int i = n; i >= 0; i--){
        cout << a[i] << endl;
    }
    return 0;
}